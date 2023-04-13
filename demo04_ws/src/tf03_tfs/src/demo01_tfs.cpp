#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"

#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
/* 
    订阅方:1.计算son1 son2的相对关系 2.计算son1中的某个座标点在son2中的坐标值
    流程:
        1.包含头文件
        2.编码\初始化ROS节点\NodeHandle
        3.创建订阅对象
        4.编写解析逻辑
        5.spinOnce();
*/

int main(int argc, char *argv[])
{
    // 2.编码\初始化ROS节点\NodeHandle
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"tfs_sub");
    ros::NodeHandle nh;
    // 3.创建订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    // 4.编写解析逻辑
    //4-1.创建座标点
    geometry_msgs::PointStamped psAtSon1;
    psAtSon1.header.stamp = ros::Time::now();
    psAtSon1.header.frame_id = "son1";
    psAtSon1.point.x = 1.0;
    psAtSon1.point.y = 2.0;
    psAtSon1.point.z = 3.0;


    ros::Rate rate(10);
    while (ros::ok())
    {
        try
        {
            // 1.计算son1 son2的相对关系 
            /* 
                A相对与B的坐标系关系

                参数1:目标坐标系 B
                参数2:源坐标系 A
                参数3:ros::Time(0) 取间隔最短的两个坐标系关系帧计算相对关系
                返回值:geometry_msgs::TransformStamped 源相对于目标坐标系的相对关系
             */
            geometry_msgs::TransformStamped son1ToSon2 = buffer.lookupTransform("son2","son1",ros::Time(0));
            ROS_INFO("son1 相对于 son2 的信息: 父级名称:%s, 子级名称:%s",
            son1ToSon2.header.frame_id.c_str(),//son2
            son1ToSon2.child_frame_id.c_str()//son1
            );
            // 2.计算son1中的某个座标点在son2中的坐标值
            geometry_msgs::PointStamped psAtSon2 = buffer.transform(psAtSon1,"son2");
            ROS_INFO("座标点在Son2中的值(%2.f,%2.f,%2.f),偏移量(%2.f,%2.f,%2.f)",
                    psAtSon2.point.x,
                    psAtSon2.point.y,
                    psAtSon2.point.z,
                    son1ToSon2.transform.translation.x,
                    son1ToSon2.transform.translation.y,
                    son1ToSon2.transform.translation.z
                    );
        }
        catch(const std::exception& e)
        {
            ROS_INFO("错误提示:%s",e.what());
            // std::cerr << e.what() << '\n';
        }
        
        
        rate.sleep();
        // 5.spinOnce();
        ros::spinOnce();
    }
    
    
    return 0;
}
