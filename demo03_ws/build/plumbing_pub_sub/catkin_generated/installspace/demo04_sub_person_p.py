#!/usr/bin/env python3
import rospy
from plumbing_pub_sub.msg import Person #发布的消息类型

"""
    使用python实现消息订阅
        1.导包
        2.初始化ros节点
        3.创建订阅者对象
        4.处理订阅的数据
        5.spin()
"""

def doPerson(p):
    rospy.loginfo("订阅的消息是：%s,%d,%.2f",p.name,p.age,p.height)


if __name__ == "__main__":
    # 2.初始化ros节点
    rospy.init_node("daYe")
    # 3.创建订阅者对象
    sub = rospy.Subscriber("jiaoSheTou",Person,doPerson)
    # 4.处理订阅的数据
    
    # 5.spin()
    rospy.spin()

    pass 