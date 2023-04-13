#include "ros/ros.h"
#include "std_msgs/String.h"
/* 
    需求：演示不同类型的话题名称设置
        设置话题名称与命名空间
 */

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello");

    // ros::NodeHandle nh;
    // 核心：设置不同类型的话题
    //1.全局 --- 话题名称设置时候以“/”开头(也可以设置话题自己的命名空间),这种情况下 话题与节点的namespace和名称没有任何关系
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter",1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter",1000);

    //2.相对 --- 非"/"开头" 与namespace挂钩
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);
    
    //3.私有 --- 需要创建指定nodehandle
    ros::NodeHandle nh("~");//~标记了私有nh
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);
    ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter",1000);//这种情况下会设置为全局话题
    //注意:如果私有nh创建的话题以/开头,则创建为全局话题

    while(ros::ok())
    {

    }

    return 0;
}
