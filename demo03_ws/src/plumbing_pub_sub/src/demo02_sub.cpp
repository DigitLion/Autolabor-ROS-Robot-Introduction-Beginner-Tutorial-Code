#include "ros/ros.h"
#include "std_msgs/String.h"
/* 
    订阅方实现：
        1.包含头文件
            ROS中文本类型 ———— std_msgs/String.h
        2.初始化ROS节点
        3.创建节点句柄
        4.创建订阅者对象
        5.处理订阅到的数据
        6.声明spin

*/
void doMsg(const std_msgs::String::ConstPtr &msg)//传入的是订阅消息的常量指针的引用
{
    //通过msg参数获取并操作订阅到的数据
    ROS_INFO("cuiHua订阅到的数据:%s",msg->data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    //2.初始化ROS节点
    ros::init(argc,argv,"cuiHua");
    //3.创建节点句柄
    ros::NodeHandle nh;
    //4.创建订阅者对象
    ros::Subscriber sub = nh.subscribe("fang",10,doMsg);//订阅函数可以理解为外部中断fang类型的消息触发
    //ros::Subscriber sub = nh.subscribe<std_msgs::Strings>("fang",10,doMsg);
    //这里不添加<std_msgs::Strings>是因为范型可以根据订阅的数据自动推导
    //5.处理订阅到的数据

    ros::spin();//循环读取接收的数据，并调用回调函数处理

    return 0;
}
