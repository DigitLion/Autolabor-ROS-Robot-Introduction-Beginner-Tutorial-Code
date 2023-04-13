#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
/* 
    客户端实现：提交两个整数，并处理响应的结果
        1.包含头文件
        2.初始化ROS节点
        3.创建节点句柄
        4.创建客户端对象
        5.提交请求并处理响应

    实现参数的动态提交：
        1.格式:rosrun xxxx xxxxx 12 34
        2.节点在执行时，需要获取命令中的参数，并组织进request

    问题：
        先启动客户端会请求异常
    需求：
        先启动客户端，不抛出异常，而是挂起并等待服务器启动后再正常请求
    解决：
        在ROS中内置了相关函数，这些函数可以让客户端启动后挂起，等待服务器启动
        client.waitForExistence();
        ros::service::waitForService("服务话题");
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //优化实现，获取命令中参数
    if(argc!=3)
    {
        ROS_INFO("提交的参数个数不对");
        return 1;
    }
    
    // 2.初始化ROS节点
    ros::init(argc,argv,"wo");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建客户端对象
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    // 5.提交请求并处理响应
    plumbing_server_client::AddInts ai;
    // 5-1.组织请求
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);
    // 5.2.处理响应
    //调用判断服务器状态函数
    //函数1
    // client.waitForExistence();
    //函数2
    ros::service::waitForService("addInts");
    bool flag = client.call(ai);
    if (flag)
    {
        ROS_INFO("响应成功～");
        //获取结果
        ROS_INFO("响应结果 = %d",ai.response.sum);
    }
    else
    {
        ROS_INFO("处理失败！");
    }

    return 0;
}
