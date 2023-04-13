#include "ros/ros.h"
#include "nodelet/nodelet.h"
#include "pluginlib/class_list_macros.h"
#include "std_msgs/Float64.h"

/* 
    需求：
        1.需要订阅一个浮点数据
        2.将订阅的数据与参数服务器的指定参数相加
        3.将最终结果发布
    流程：
        1.去顶需要的变量：订阅对象，发布对象，存储参数的变量
        2.因为manager已经启动节点 省去初始化 直接获取NodeHandle
        3.通过Nodehandle创建订阅对象和发布对象，解析参数；
        4.订阅对象的回调函数需要处理数据并通过发布对象发布
 */

namespace my_nodelet
{
    class MyPlus: public nodelet::Nodelet{
        private:
            ros::Publisher pub;
            ros::Subscriber sub;
            double value;
        public:
            MyPlus(){
                value = 0.0;
            };
            void onInit(){
                ROS_INFO("hello nodelet -------------- ");
            // 2.因为manager已经启动节点 省去初始化 直接获取私有的NodeHandle
            ros::NodeHandle nh = getPrivateNodeHandle();
            // 3.通过Nodehandle创建订阅对象和发布对象，解析参数；
            nh.getParam("value",value);
            pub = nh.advertise<std_msgs::Float64>("out",100);//话题名称：/节点名/in;
            sub = nh.subscribe<std_msgs::Float64>("in",100,&MyPlus::cb,this);
            // 4.订阅对象的回调函数需要处理数据并通过发布对象发布
            };
            void cb(const std_msgs::Float64::ConstPtr& p){
                //4-1.解析订阅的数据
                double in = p->data;
                //4-2.和参数相加
                double out = in + value;
                //4-3.发布
                std_msgs::Float64 out_msg;
                out_msg.data = out;
                pub.publish(out_msg);
            }


    };
} // namespace my_nodelet

PLUGINLIB_EXPORT_CLASS(my_nodelet::MyPlus,nodelet::Nodelet)

