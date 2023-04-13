#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

/* 
    发布方实现：
        1.包含头文件
            ROS中文本类型 ———— std_msgs/String.h
        2.初始化ROS节点
        3.创建节点句柄
        4.创建发布者对象
        5.编写发布逻辑并发布数据

*/

int main(int argc, char *argv[])
{
    // setlocale(LC_CTYPE, "zh_CN.utf8");
    setlocale(LC_ALL,"");
    //2.初始化ROS节点
    ros::init(argc,argv,"erGouZi");
    //3.创建节点句柄
    ros::NodeHandle nh;
    //4.创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);
    //5.编写发布逻辑并发布数据
    //要求以10hz频率发布数据,并标注编号

    //先创建被发布的消息
    std_msgs::String msg;
    //发布频率
    ros::Rate rate(2);
    //设置编号
    int count = 0;
    ros::Duration(1).sleep();//给发布者在master注册的时间，防止订阅者错失数据
    //编写循环,循环中发布数据
    while (ros::ok())
    {
        count++;
        //实现字符串拼接数字
        std::stringstream ss;
        ss << "hello ---> "<<count;
        // msg.data = "hello";
        msg.data = ss.str();

        pub.publish(msg);
        
        //添加日志
        ROS_INFO("erGouZi发布的数据是:%s",ss.str().c_str());

        rate.sleep();//根据发布频率休眠
        ros::spinOnce();//虽然没有回调函数 但是官方建议添加
    }
    
    return 0;
}
