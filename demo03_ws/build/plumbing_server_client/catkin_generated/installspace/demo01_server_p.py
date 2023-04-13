#!/usr/bin/env python3

import rospy
# from plumbing_server_client.srv import AddInts, AddIntsRequest, AddIntsResponse
from plumbing_server_client.srv import *  #文件特别大时别这么用，处理时间会变慢很多
""" 
    服务端：解析客户端请求，产生响应
        1.导包
        2.初始化ROS节点
        3.创建服务端对象
        4.处理逻辑（回调函数）
        5.spin()
"""


#参数：封装请求数据
#返回值：响应数据
def doNum(request: AddIntsRequest):
    #1.解析提交的两个整数
    num1 = request.num1
    num2 = request.num2
    #2.求和
    sum = num1 + num2
    #3.封装至响应
    response = AddIntsResponse()
    response.sum = sum
    rospy.loginfo("服务器解析了数据num1 = %d, num2 = %d, 响应的结果sum = %d", num1, num2,
                  response.sum)
    return response


if __name__ == "__main__":
    # 2.初始化ROS节点
    rospy.init_node("heiShui")
    # 3.创建服务端对象
    server = rospy.Service("addInts", AddInts, doNum)
    rospy.loginfo("服务器已经启动")
    # 4.根据触发条件，处理逻辑（回调函数）

    # 5.spin()
    rospy.spin()
    pass