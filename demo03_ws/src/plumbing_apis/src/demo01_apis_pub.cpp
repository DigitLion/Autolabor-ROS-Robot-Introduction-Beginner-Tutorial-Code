#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

/* 
    发布方实现：
        1.包含头文件
            ROS中文文本类新 ---> std_msgs/String.h
        2.初始化ROS节点
        3.创建节点句柄
        4.创建发布者对象
        5.编写发布逻辑并发布数据
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //2.初始化ROS节点
    /* 
        作用：ROS初始化函数

        参数：
            1.argc  ---> 程序调用时封装实参的个数（n+1）第一个是文件自身
            2.argv  ---> 程序调用时封装参数的数组（字符串）
            3.name  ---> 为节点命名（保证唯一性）
            4.options   节点启动选项

            返回值：oid
        使用：
            1.argc与argv的使用
              如果按照ROS中的特定格式传入实参，那么ROS可以利用，eg:设置全局参数、给节点重命名
            2.options的使用
              节点名称要保持唯一，会导致同名节点不能重复启动
              需求：特定场景下，需要一个节点多次启动且正常运行
              解决：ROS初始化中设置启动项：ros::init_options::AnonymousName
                当创建ROS节点时，会在用户自定义的节点名称后缀随机数，避免重名问题
    */
    ros::init(argc,argv,"erGouZi",ros::init_options::AnonymousName);
    //3.创建节点句柄
    ros::NodeHandle nh;
    /* 
        作用：创建发布者对象

        模板：被发布的消息类型

        参数：
            1.话题名称
            2.队列长度
            3.latch(可选)  如果设置为true，会保存发布方最后一条消息，
            并在新的定语对象连接到发布方时，发布方会将这条信息发送给新的订阅者

        使用：
            latch设置为true的作用：导航场景 静态地图 发布逻辑调整
                方案一：固定频率发送效率太低
                方案二：latch为true则可以根据订阅者的连接与否实现发布方的消息发送（对所有请求的订阅者都只发送一次）从而提升发送效率


    */
    //4.创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10,true);
    //5.编写发布逻辑并发布数据
    //要求以10hz频率发布数据,并标注编号
    //先创建被发布的消息
    std_msgs::String msg;
    //发布频率
    ros::Rate rate(1);
    //设置编号
    int count = 0;
    ros::Duration(1).sleep();//给发布者在master注册的时间，防止订阅者错失数据
    //编写循环,循环中发布数据
    while (ros::ok())
    {
        //如果count >=50 关闭节点
        if(count>=50)
        {
            ros::shutdown();
        }
        //-----------------------------------
        
        count++;
        //实现字符串拼接数字
        std::stringstream ss;
        ss << "hello ---> "<<count;
        // msg.data = "hello";
        msg.data = ss.str();

        if(count <= 50)
        {
            pub.publish(msg);
            ROS_INFO("erGouZi发布的数据是:%s",ss.str().c_str());    
        }

        //添加日志
        rate.sleep();//根据发布频率休眠
        ros::spinOnce();//虽然没有回调函数 但是官方建议添加
        ROS_INFO("一轮回调执行完毕");
    }
    
    return 0;
}
