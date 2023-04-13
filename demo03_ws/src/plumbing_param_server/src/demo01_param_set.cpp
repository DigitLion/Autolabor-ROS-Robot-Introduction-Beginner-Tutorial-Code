#include "ros/ros.h"

/* 
    需要实现参数的新增与修改：
    需求：
        1.设置机器人共享参数：类型、半径（0.15m）
        2.修改半径参数（0.2m）
    实现：
        1.ros::NodeHandle
            setParam("键",值)
        2.ros::param
            set("键",值)
        3.修改仅需保证相同“键”下，继续调用setParam或者set，
*/

int main(int argc, char *argv[])
{
    //初始化ROS节点
    ros::init(argc,argv,"set_param_c");
    //创建ROS节点句柄
    ros::NodeHandle nh;

    //参数增加
    //1.nh
    nh.setParam("type","xiaoHuang");
    nh.setParam("radius",0.15);
    //2.ros::param
    ros::param::set("type_param","xiaoBai");
    ros::param::set("radius_param",0.15);

    //参数修改
    //1.nh
    nh.setParam("radius",0.2);
    //2.ros::param
    ros::param::set("radius_param",0.25);
    return 0;
}
