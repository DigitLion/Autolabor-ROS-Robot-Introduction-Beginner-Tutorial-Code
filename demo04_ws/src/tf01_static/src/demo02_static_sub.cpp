#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

/* 
    订阅方实现:订阅发布方的坐标系相对关系,并传入一个坐标点,调用tf实现转换

    流程:
        1.包含头文件
        2.编码设置\节点初始化\NodeHandle(订阅方必须)
        3.创建订阅对象 ---> 订阅坐标系相对关系
        4.组织一个坐标点数据
        5.转换算法,调用tf内置实现
        6.输出转化结果

*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2.编码设置\节点初始化\NodeHandle(订阅方必须)
    ros::init(argc,argv,"static_sub");
    ros::NodeHandle nh;
    // 3.创建订阅对象 ---> 订阅坐标系相对关系
    // 3-1.创建一个buffer缓存
    tf2_ros::Buffer buffer;
    // 3-2.创建监听对象(将订阅的数据存入buffer)
    tf2_ros::TransformListener linsener(buffer);
    // 4.组织一个坐标点数据
    geometry_msgs::PointStamped ps;
    ps.header.frame_id = "laser";
    ps.header.stamp = ros::Time::now();
    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;
/*  
添加休眠:
    terminate called after throwing an instance of 'tf2::LookupException'
    what():  "base_link" passed to lookupTransform argument target_frame does not exist. 
    已放弃 (核心已转储) 
*/
    // ros::Duration(2).sleep();
    // 5.转换算法,调用tf内置实现
    ros::Rate rate(10);
    while (ros::ok())
    {
        //核心代码 -- 将ps转换成相对于base_link的坐标点
        // geometry_msgs::PointStamped ps_out;
        // ps_out = buffer.transform(ps,"base_link");//转换过程中需要调用自身封装的ft消息方法
        /* 
            调用了buffer的转换函数transform
            参数1:被转换的坐标点
            参数2:目标坐标系
            返回值:输出坐标点

            PS1:调用时必须包含头文件ft2_geometry_msgs.h
            PS2:异常:"base_link"不存在 
                原因:订阅数据是一个耗时操作,调用transform转换的时候,坐标系的相对关系数据还没有传送到buffer里
                解决:
                    方案1:在调用转换函数前,执行休眠
                    方案2:进行异常处理:try
        */

        try
        {
            geometry_msgs::PointStamped ps_out;
            ps_out = buffer.transform(ps,"base_link");
            // 6.输出转化结果
            ROS_INFO("转换后的坐标值(%.2f,%.2f,%.2f),参考的坐标系%s",
                    ps_out.point.x,
                    ps_out.point.y,
                    ps_out.point.z,
                    ps_out.header.frame_id.c_str()
                    );
        }
        catch(const std::exception& e)
        {
            ROS_INFO("异常消息:%s",e.what());
        }
        rate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
