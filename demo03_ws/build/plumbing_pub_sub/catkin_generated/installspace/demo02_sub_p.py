#!/usr/bin/env python3
import rospy
from std_msgs.msg import String #发布的消息类型

"""
    使用python实现消息订阅
        1.导包
        2.初始化ros节点
        3.创建订阅者对象
        4.回调函数处理数据
        5.spin()
"""

def doMsg(msg):
    rospy.loginfo("订阅的数据是：%s",msg.data)


if __name__ == "__main__":
    # 2.初始化ros节点
    rospy.init_node("huaHua")
    # 3.创建订阅者对象
    rospy.Subscriber("fang",String,doMsg,queue_size=10)
    # 4.回调函数处理数据
    
    # 5.spin()
    rospy.spin()

    pass 