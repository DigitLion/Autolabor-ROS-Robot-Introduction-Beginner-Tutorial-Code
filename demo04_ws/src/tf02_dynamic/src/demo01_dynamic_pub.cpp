#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

/* 
    杀掉所有ros进程:ps -ef|grep ros|awk '{print $2}'|xargs kill -9 
    发布方:需要订阅乌龟的位姿信息并转换成相对于世界坐标系(窗体)的坐标关系,最后发布出去
    准备:
        乌龟话题:/turtle1/pose
        乌龟消息:turtlesim/Pose
    流程:
        1.包含头文件
        2.初始化:编码\ros节点\nh创建
        3.创建一个订阅对象,订阅/turtle1/pose
        4.回调函数处理订阅的消息:将位姿信息转换成坐标相对关系并发布(关注)
        5.spin()
*/

void doPose(const turtlesim::Pose::ConstPtr& pose)
{
    //获取位姿信息,转换成坐标系相对关系(核心)并发布
    //a.创建发布对象
    static tf2_ros::TransformBroadcaster pub;//每次调用时只调用一次初始化
    //b.组织被发布的数据(从pose转换而来)
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = "turtle1";
    //坐标系偏移量
    ts.transform.translation.x = pose->x; 
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;//乌龟在平面里无z,是0
    //坐标系四元数
    /* 
        乌龟位姿信息中没有四元数,但是有个偏航角度,
        又已知乌龟是2D,没有翻滚row与俯仰角度,所以可以得到:
        乌龟的欧拉角度:0,0,theta    
    */
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);

    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();
    //c.发布
    pub.sendTransform(ts);
}


int main(int argc, char *argv[])
{
    // 2.初始化:编码\ros节点\nh创建
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_pub");
    ros::NodeHandle nh;
    // 3.创建一个订阅对象,订阅/turtle1/pose
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",100,doPose);
    // 4.回调函数处理订阅的消息:将位姿信息转换成坐标相对关系并发布(关注)
    // 5.spin()
    ros::spin();
    return 0;
}