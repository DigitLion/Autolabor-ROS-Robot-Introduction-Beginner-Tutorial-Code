#include "ros/ros.h"
#include "turtlesim/Pose.h"

/* 
    需求：订阅小乌龟的位姿信息并输出打印至控制台
    准备工作:
        1.获取话题名称 /turtle1/pose
        2.获取消息类型 turtlesim/Pose
        3.运行前启动 turtlesim_node 与 turtle_teleop_key 节点（roslaunch start_turtle）

    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 句柄
        4.创建订阅者对象
        5.回调函数处理订阅的数据(回调函数)
        6.spin

 */

//处理订阅到的数据
void doPose(const turtlesim::Pose::ConstPtr &pose)
{
    ROS_INFO("乌龟的位姿信息：坐标(%.2f,%.2f),朝向(%.2f,%.2f),线速度:%.2f,角速度:%.2f",
            pose->x,pose->y,pose->theta,pose->linear_velocity,pose->angular_velocity);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ROS 节点
    ros::init(argc,argv,"sub_pose");
    // 3.创建 ROS 句柄
    ros::NodeHandle nh;
    // 4.创建订阅者对象
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",100,doPose);
    // 5.回调函数处理订阅的数据(回调函数)
    // 6.spin
    ros::spin();
    return 0;
}
