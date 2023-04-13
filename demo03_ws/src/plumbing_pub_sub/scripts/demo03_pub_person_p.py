#! usr/bin/env/ python
import rospy
from plumbing_pub_sub.msg import Person #发布的消息类型

"""
    使用python实现消息发布
        1.导包
        2.初始化ros节点
        3.创建发布者对象
        4.组织发布逻辑并发布数据
"""


if __name__ == "__main__":
    # 2.初始化ros节点
    rospy.init_node("daMa")
    # 3.创建发布者对象
    pub = rospy.Publisher("jiaoSheTou",Person,queue_size=10)#注意que_size与C的区别
    # 4.组织发布逻辑并发布数据
    #4.1创建数据
    p = Person()
    p.name = "autoMan"
    p.age = 1
    p.height = 165.5
    #4.2制定发布频率
    rate = rospy.Rate(1)
    rospy.sleep(3)#给发布者在master注册的时间，防止订阅者错失数据
    #4.3设置循环发布数据
    while not rospy.is_shutdown():
        pub.publish(p)
        rospy.loginfo("发布的消息：%s,%d,%.2f",p.name,p.age,p.height)
        p.age += 1
        rate.sleep()

    pass