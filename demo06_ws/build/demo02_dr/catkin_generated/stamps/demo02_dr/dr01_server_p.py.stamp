#! usr/bin/env python

import rospy
from dynamic_reconfigure.server import Server
from demo02_dr.cfg import drConfig

""" 
    动态参数服务端流程：
        1.导包
        2.初始化ROS节点
        3.创建服务端对象
        4.回调函数解析参数
        5.spin()
"""

def cb(drConfig,level):
    rospy.loginfo("解析的参数：%d,%.2f,%s,%d,%d",
                    drConfig.int_param,
                    drConfig.double_param,
                    drConfig.str_param,
                    drConfig.bool_param,
                    drConfig.list_param
                  )
    return drConfig

if __name__ == "__main__":
    # 2.初始化ROS节点
    rospy.init_node("dr_server_p")
    # 3.创建服务端对象
    # Server(type: Any, callback: Any, namespace: str = "") -> None
    # type类型 callback回调函数
    server = Server(drConfig,cb)
    # 4.回调函数解析参数
    # 5.spin()
    rospy.spin()
    pass