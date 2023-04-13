#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

/*
    需求：该节点需要发布两个坐标系的相对关系

    流程：
        1.包含头文件：
        2.设置编码、节点初始化（NodeHandle）
        3.创建发布对象
        4.组织被发布消息
        5.发布数据
        6.spin()
*/
int main(int argc, char *argv[])
{
    // 2.设置编码、节点初始化（发布方NodeHandle非必须）
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_pub");
    ros::NodeHandle nh;
    // 3.创建发布对象(静态坐标转换广播器)
    tf2_ros::StaticTransformBroadcaster pub;
    // 4.组织被发布消息(创建坐标信息)
    geometry_msgs::TransformStamped tfs;
    tfs.header.seq = 100;//可以不设置?
    tfs.header.stamp = ros::Time::now();
    tfs.header.frame_id = "base_link";//相对坐标系关系中被参考的那一个
    //设置子级相对于父级的偏移量
    tfs.child_frame_id = "laser";
    tfs.transform.translation.x = 0.2;
    tfs.transform.translation.y = 0.0;
    tfs.transform.translation.z = 0.5;
    //需要根据欧拉角转换(调用Quaternion)
    tf2::Quaternion qtn;//创建四元数对象
    //向该对象传递欧拉角,这个对象可以将其转换成四元数Pre-configure failed: no script provided.
    qtn.setRPY(0,0,0);//此处欧拉角单位是弧度
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();

    // 5.发布数据
    pub.sendTransform(tfs);
    // 6.spin()
    ros::spin();
    return 0;
}
/* 
    测试验证:rviz
    选择base_link
    Add
    TF
 */