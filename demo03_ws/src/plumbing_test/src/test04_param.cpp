#include "ros/ros.h"
/* 
    需求：修改参数服务中turtlesim背景色相关参数

    1.初始化ros节点
    2.不一定需要创建节点句柄（与后续调用的API有关）
    3.修改参数

*/
int main(int argc, char *argv[])
{
    // 1.初始化ros节点
    ros::init(argc,argv,"change_bgColor");
    // 2.不一定需要创建节点句柄（与后续调用的API有关）
    // 3.修改参数
       
    // 3-1.调用ros::param时不需要调用节点句柄
    // ros::param::set("/turtlesim/background_r",0);
    // ros::param::set("/turtlesim/background_g",0);
    // ros::param::set("/turtlesim/background_b",0);
    
    // 3-2.nodehandle
    ros::NodeHandle nh;
    nh.setParam("/turtlesim/background_r",255);
    nh.setParam("/turtlesim/background_g",255);
    nh.setParam("/turtlesim/background_b",255);

    return 0;
}
