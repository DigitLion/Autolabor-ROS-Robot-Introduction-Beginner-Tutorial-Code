#!/usr/bin/env python

import rospy
import rosbag
from std_msgs.msg import String
""" 
    需求:读取磁盘上的bag文件
    流程:
        1.导包
        2.初始化
        3.读的方式创建rosbag对象并打开文件流
        4.读取数据
        5.关闭流
"""

if __name__ == "__main__":
    # 2.初始化
    rospy.init_node("read_bag_p")
    # 3.读的方式创建rosbag对象并打开文件流
    bag = rosbag.Bag("hello_p.bag", 'r')
    # 4.读取数据
    msgs = bag.read_messages("/liaoTian")
    for topic, msg, time in msgs:
        rospy.loginfo("话题:%s,内容:%s,时间:%s", topic, msg.data,time)
    # 5.关闭流
    bag.close()
    pass
