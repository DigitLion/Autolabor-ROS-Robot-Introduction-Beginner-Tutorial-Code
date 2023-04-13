#include "ros/ros.h"
#include "actionlib/client/simple_action_client.h"
#include "demo01_action/AddIntsAction.h"
/* 
    需求:
        创建两个ROS节点，服务器和客户端，
        客户端可以向服务器发送目标数据N（一个整型数据）
        服务器会计算1到N之间所有整数的和，这是一个循环累加的过程，返回给客户端，
        这是基于请求响应模式的，
        又已知服务器从接收到请求到产生响应是一个耗时操作，每累加一次耗时0.1s，
        为了良好的用户体验，需要服务器在计算过程中，
        每累加一次，就给客户端响应一次百分比格式的执行进度，使用action实现。
    流程：
        1.包含头文件
        2.初始化ROS节点
        3.创建NodeHandle
        4.创建action客服端对象（等待服务启动）
        5.发送请求
            a.链接建立； --- 回调函数
            b.处理连续反馈 --- 回调函数1
            c.处理最终响应 --- 回调函数2
        6.spin()回旋
 */
//激活回调
void active_cb()
{
    ROS_INFO("客户端与服务端链接已建立...");
}
//连续反馈回调
void feedback_cb(const demo01_action::AddIntsFeedbackConstPtr &feedback )
{
    ROS_INFO("当前进度:%.2f",feedback->progress_bar);
}
//响应成功时候的回调
void done_cb(const actionlib::SimpleClientGoalState &state, const demo01_action::AddIntsResultConstPtr &result)
{
    //响应是否成功
    if (state.state_ == state.SUCCEEDED)
    {
        ROS_INFO("响应成功，最终结果 = %d",result->result);
    }
    else
    {
        ROS_INFO("请求失败...");
    }   
}

int main(int argc, char *argv[])
{
    // 2.初始化ROS节点
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"addInts_client");
    // 3.创建NodeHandle
    ros::NodeHandle nh;
    // 4.创建action客户端对象
    actionlib::SimpleActionClient<demo01_action::AddIntsAction> client(nh,"addInts");
    // 5.发送请求
    //注意：先等待服务
    ROS_INFO("等待服务器启动...");
    client.waitForServer();
    //     a.链接建立； --- 回调函数
    //     b.处理连续反馈 --- 回调函数1
    //     c.处理最终响应 --- 回调函数2
    /* 
    void sendGoal(const demo01_action::AddIntsGoal &goal, 
                boost::function<void (const actionlib::SimpleClientGoalState &state, const demo01_action::AddIntsResultConstPtr &result)> done_cb, 
                boost::function<void ()> active_cb, 
                boost::function<void (const demo01_action::AddIntsFeedbackConstPtr &feedback)> feedback_cb)
     */
    //参数1:设置目标值
    demo01_action::AddIntsGoal goal;
    goal.num = 100;
    //参数2：
    client.sendGoal(goal,&done_cb,&active_cb,&feedback_cb);
    // 6.spin()回旋
    ros::spin();
    return 0;
}
