#include "ros/ros.h"


/* 
    需求：演示时间相关操作（获取当前时间+指定时刻）
    实现：
        1.准备（头文件、节点初始化、NodeHandle创建...）
        2.获取当前时刻
        3.设置指定时刻

    注意：
        1.时刻与时间可以作+-操作
        2.时间之间也可以+-操作
        3.时刻之间只可以-操作

    注意：
        创建nh.creatTimer()
        参数1：时间间隔
        参数2：回调函数（时间事件 TimerEvent）
        参数3：是否只执行一次
        参数4：是否自动启动（设置为false需要手动调用timer.start()）

        定时器启动后：ros.spin();

*/

void cb(const ros::TimerEvent& event)
{
    ROS_INFO("---------");
    ROS_INFO("函数被调用的时刻：%.2f",event.current_real.toSec());
    
}

int main(int argc, char *argv[])
{
    // 1.准备（头文件、节点初始化、NodeHandle创建...）
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello_time");

    //注意：必须，否则会导致时间API调用失败（再NodeHandle会初始化时间操作）
    ros::NodeHandle nh; 

    // 2.获取当前时刻
    // now()函数会将当前时刻封装并返回（当前时刻：now被执行的那一刻）
    // 参考系：1970.1.1 +8h 0m 0s
    ros::Time right_now = ros::Time::now();
    ROS_INFO("当前时刻%.2f",right_now.toSec());
    ROS_INFO("当前时刻%d",right_now.sec);
    // 3.设置指定时刻
    ros::Time t1(20,312345678);//20.31s
    ros::Time t2(100.35);

    ROS_INFO("t1 = %.2f",t1.toSec());
    ROS_INFO("t2 = %.2f",t2.toSec());
//------------------------------------------------------------------
    /* 
    需求2：程序执行中停顿5s
    实现：
        1.创建持续时间对象
        2.休眠

    */
    
    ROS_INFO("----------持续时间-----------");
    ros::Duration du(0.5);//持续时间4.5s
    ros::Time start = ros::Time::now();

    ROS_INFO("开始休眠:%.2f",start.toSec());
    du.sleep();//休眠
    ros::Time end = ros::Time::now();
    ROS_INFO("休眠结束:%.2f",end.toSec());

//------------------------------------------------------------------
    /* 
    需求3：已知程序开始运行的时刻，程序运行时间，求程序运行结束的时刻
    实现：
        1.获取开始执行的时刻
        2.模拟运行时间（n秒）
        3.计算结束时刻 = 开始+持续时间

    */
    ROS_INFO("----------持续运算-----------");
    //时刻与时间运算
    ros::Time begin = ros::Time::now();
    ros::Duration du1(5);
    ros::Time stop = begin +du1;

    ROS_INFO("开始时刻：%.2f",begin.toSec());
    ROS_INFO("开始时刻：%.2f",stop.toSec());
    //时刻与时刻运算
    // ros::Time sum = begin + stop; // 不可以相加
    ros::Duration du2 = begin - stop;//可以
    ROS_INFO("时刻相减：%.2f",du2.toSec());
    //时间与时间运算
    ros::Duration du3 = du1 + du2;
    ros::Duration du4 = du1 - du2;
    ROS_INFO("du1 + du2 = %.2f",du3.toSec());
    ROS_INFO("du1 - du2 = %.2f",du4.toSec());
//------------------------------------------------------------------
    /* 
    需求4：每间隔1s，在控制台中输出一段文本
    实现：
        1.策略1：ros::Rate(1);
        2.策略2：定时器
        ros::Timer createTimer(ros::Duration period,    //时间间隔 --- 1s
            const ros::TimerCallback &callback,         //回调函数 --- 封装业务
            bool oneshot = false,                       //是否是一次性的
            bool autostart = true)                      //是否自动启动

    */
    ROS_INFO("----------定时器-----------");
    ros::Timer timer = nh.createTimer(ros::Duration(1),cb,false,false);
    timer.start();
    ros::spin();//需要回旋

    return 0;
}
