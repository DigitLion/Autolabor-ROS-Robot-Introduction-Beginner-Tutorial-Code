#! /usr/bin/env python

import rospy
from std_msgs.msg import String #发布的消息类型
""" 
    使用python实现消息发布
        1.导包
        2.初始化ros节点
        3.创建发布者对象
        4.编写发布逻辑并发布数据
"""

import os
#设置临时环境变量
import sys
#路径写死,影响代码可以执行性
# sys.path.insert(0,"/home/john/demo03_ws/src/plumbing_pub_sub/scripts")
#动态获取路径/home/john/demo03_ws/
path = os.path.abspath(".")
sys.path.insert(0,path + "/src/plumbing_pub_sub/scripts")
import tools

if __name__ == "__main__":

    #异常:ModuleNotFoundError: No module named 'tools'
    #原因:rosrun执行时参考路径是工作空间的路径?
    #解决:声明python的环境变量,当依赖某模块时,先去指定的环境变量中查找相关环境变量
    rospy.loginfo("执行时参考的路径是:%s",path)
    rospy.loginfo("num = %d",tools.num)

    #2.初始化ros节点
    rospy.init_node("sanDai")#传入节点名称
    #3.创建发布者对象
    pub = rospy.Publisher("che",String,queue_size=10)
    #4.编写发布逻辑并发布数据
    #创建数据
    msg = String() 
    #制定发布频率
    rate = rospy.Rate(1)
    #设置计数器
    count = 0
    #使用循环发布数据
    rospy.sleep(3)#给发布者在master注册的时间，防止订阅者错失数据
    while not rospy.is_shutdown():
        count += 1
        msg.data = "hello" + str(count)
        pub.publish(msg)
        rospy.loginfo("发布的数据是：%s",msg.data)
        rate.sleep()


    #发布数据
    pass