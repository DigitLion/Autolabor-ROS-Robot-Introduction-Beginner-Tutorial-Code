#include "ros/ros.h"
#include "pluginlib/class_loader.h"
#include "demo03_plugin/dbx_base.h"
/* 
    创建类加载器，根据需求加载相关插件
        1.创建类加载器
        2.使用类加载器实例化某个插件
        3.使用插件
 */

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 1.创建类加载器
    pluginlib::ClassLoader<dbx_base_ns::Dbx_Base> loader("demo03_plugin","dbx_base_ns::Dbx_Base");
    
    try
    {
        // 2.使用类加载器实例化某个插件
        boost::shared_ptr<dbx_base_ns::Dbx_Base> san = loader.createInstance("dbx_plugins_ns::SanBian");
        // 3.使用插件
        san->init(10);
        double length = san->getlength();
        ROS_INFO("三角形周长：%.2f",length);

        // 2.使用类加载器实例化某个插件
        boost::shared_ptr<dbx_base_ns::Dbx_Base> si = loader.createInstance("dbx_plugins_ns::SiBian");
        // 3.使用插件
        si->init(10);
        double length2 = si->getlength();
        ROS_INFO("四边形周长：%.2f",length2);
    }
    catch(pluginlib::PluginlibException& ex)
    { 
        ROS_ERROR("The plugin failed to load for some reason. Error: %s", ex.what());
    }

    return 0;
}
