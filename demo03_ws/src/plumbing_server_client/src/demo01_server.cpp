#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
/* 
    服务端实现：解析客户端提交的数据，并运算再产生响应
        1.包含头文件
        2.初始化ROS节点
        3.创建节点句柄
        4.创建服务对象
        5.处理请求并产生响应
        6.spin()
*/

bool doNums(plumbing_server_client::AddInts::Request &request, 
            plumbing_server_client::AddInts::Response &response)
{
    //1.处理请求
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("收到的请求数据：num1 = %d, num2 = %d", num1, num2);
    //2.组织响应
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("求和结果：sum = %d", response.sum);
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化ROS节点
    ros::init(argc,argv,"heiShui");//节点名称需要保证唯一
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建服务对象
    ros::ServiceServer sever = nh.advertiseService("addInts",doNums);
    ROS_INFO("服务器端启动");
    // 5.处理请求并产生响应
    // 6.spin（）
    ros::spin();

    return 0;
}
