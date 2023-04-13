#include "ros/ros.h"
/* 

    演示参数查询：
        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached(键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

    ros::param ----- 与 NodeHandle 类似    
*/
int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");
    //初始化ROS节点
    ros::init(argc,argv,"get_param_c");
    //创建节点句柄
    ros::NodeHandle nh;

    /*** nh.方法 ***/
    //1.param()
    double radius = nh.param("radius",0.5);
    ROS_INFO("radius = %.2f",radius);

    //2.getParam()
    // double radius2 = 0.0;
    // bool result = nh.getParam("radius",radius2);
    // if(result)
    // {
    //     ROS_INFO("获取的半径是：%.2f",radius2);
    // }
    // else
    // {
    //     ROS_INFO("查询的变量不存在。");
    // }
    
    //3.getParamCached()--->相较于getParam性能上有提升,看不出来
    double radius3 = 0.0;
    bool result3 = nh.getParamCached("radius",radius3);
        if(result3)
    {
        ROS_INFO("获取的半径是：%.2f",radius3);
    }
    else
    {
        ROS_INFO("查询的变量不存在。");
    }

    //4.getParamNames()
    std::vector<std::string> names;
    nh.getParamNames(names);
    for(auto&& name : names)
    {
        ROS_INFO("遍历的元素：%s",name.c_str());
    }

    //5.hasParam()
    bool flag1= nh.hasParam("radius");
    bool flag2= nh.hasParam("radiusxxxx");
    ROS_INFO("radius存在?%d",flag1);
    ROS_INFO("radiusxxx存在?%d",flag2);

    //6.searchParam(key,storage)
    std::string key,key2;
    nh.searchParam("radius",key);
    ROS_INFO("搜索结果%s",key.c_str());
    nh.searchParam("radiusxxx",key2);
    ROS_INFO("搜索结果%s",key2.c_str());
    
    /*** ros::param::方法 ***/
    //1.ros::param::param
    double radius_param = ros::param::param("radiusxxx",100.5);
    ROS_INFO("radius_param = %.2f",radius_param);
    //2.ros::param::get
    double radius_get;
    bool result_get = ros::param::get("radius",radius_get);
    if(result_get)
    {
        ROS_INFO("获取的半径是：%.2f",radius_get);
    }
    else
    {
        ROS_INFO("查询的变量不存在。");
    }
    //3.ros::param::getCached
    double radius_get_2 = 0.0;
    bool result_get_2 = ros::param::getCached("radius",radius_get_2);
    if(result_get_2)
    {
        ROS_INFO("获取的半径是：%.2f",radius_get_2);
    }
    else
    {
        ROS_INFO("查询的变量不存在。");
    }

    //4.ros::param::getParamNames
    std::vector<std::string> names_param;
    ros::param::getParamNames(names_param);
    for(auto&& name : names_param)
    {
        ROS_INFO("键:%s",name.c_str());
    }    
    //5.ros::param::has
    bool flag3 = ros::param::has("radius");
    bool flag4 = ros::param::has("radiusxxx");
    ROS_INFO("radius存在?%d",flag3);
    ROS_INFO("radiusxxx存在?%d",flag4);

    //6.ros::param::serach
    std::string key3, key4;
    ros::param::search("radius",key3);
    ROS_INFO("搜索结果%s",key3.c_str());
    ros::param::search("radiusxxx",key4);
    ROS_INFO("搜索结果%s",key4.c_str());

    return 0;
}
