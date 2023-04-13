#! usr/bin/env python

import rospy
from plumbing_server_client.srv import *
import sys
""" 
    服务端：组织并提交请求，处理响应
        1.导包
        2.初始化ROS节点
        3.创建服务端对象
        4.组织请求数据，并发送请求
        5.处理响应

    优化实现：
        可以在执行节点时动态传入参数

    需求：
        客户端具备在服务端离线时自动挂起的功能
    实现：
        ROS中内置了可以判断服务器状态的相关函数
        # 方法1：等待服务启动（自动判断client对应话题）
        client.wait_for_service()
        # 方法2：制定对应话题的服务启动
        rospy.wait_for_service("addInts")

"""
if __name__ == "__main__":

    #判断传入参数是否为3个（加上默认的参数）
    if len(sys.argv) != 3:
        rospy.loginfo("传入参数个数不对")
        sys.exit(1)

    # 2.初始化ROS节点
    rospy.init_node("AddInts_Client_p")
    # 3.创建服务端对象
    client = rospy.ServiceProxy("addInts", AddInts)

    #服务器挂起判断
    # 方法1：等待服务启动（自动判断client对应话题）
    client.wait_for_service()
    # 方法2：制定对应话题的服务启动
    rospy.wait_for_service("addInts")

    # 4.组织请求数据，并发送请求
    # 解析传入参数
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])
    response = client.call(num1, num2)
    # 5.处理响应
    rospy.loginfo("响应的数据：%d", response.sum)
