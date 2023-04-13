#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello");
    ros::NodeHandle nh;

    /*
        使用ros::param来设置参数 
     */
    //1.全局
    ros::param::set("/radiusA",100);
    //2.相对
    ros::param::set("radiusB",100.1);
    //3.私有
    ros::param::set("~radiusC",100.2);

    /*
        使用NodeHandle来设置参数 
     */
    //1.全局
    nh.setParam("/radius_nh_A",10);
    //2.相对
    nh.setParam("radius_nh_B",10.1);
    //3.私有
    ros::NodeHandle nh_private("~");
    nh_private.setParam("radius_nh_C",10.2);

    return 0;
}
