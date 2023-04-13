#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

/* 
    发布方:发布人的消息
        1.包含头文件
            #include "plumbing_pub_sub/Person.h"
        2.初始化ROS节点
        3.创建ROS句柄
        4.创建发布者对象
        5.编写发布逻辑，发布数据
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("这是消息的发送方\n");
    // 2.初始化ROS节点
    ros::init(argc,argv,"banZhuRen");
    // 3.创建ROS句柄
    ros::NodeHandle nh;
    // 4.创建发布者对象
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("liaoTian",10);
    // 5.编写发布逻辑，发布数据
    //5-1.创建被发布数据
    plumbing_pub_sub::Person person;
    person.name = "张三";
    person.age = 1;
    person.height = 165.5;
    //5-2.设置发布频率
    ros::Rate rate(1);
    ros::Duration(2).sleep();
    //5-3.循环发布数据
    while(ros::ok())
    {
        //核心：数据发布
        
        pub.publish(person);
        ROS_INFO("发布的消息：%s,%d,%.2f",person.name.c_str(),person.age,person.height);
        //修改数据
        person.age += 1;
        rate.sleep();
        ros::spinOnce();//建议
    }
    return 0;
}
