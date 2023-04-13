#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello_c");
    //解决乱码问题（二选一，推荐第二条）
    setlocale(LC_CTYPE, "zh_CN.utf8");
    setlocale(LC_ALL, "");

    ROS_INFO("hello vscode_c");
    ROS_INFO("哈哈");

    return 0;
}
