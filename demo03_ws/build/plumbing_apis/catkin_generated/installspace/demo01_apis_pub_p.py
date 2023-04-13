#!/usr/bin/env python3
import rospy
from std_msgs.msg import String  #发布的消息类型
"""
    使用python实现消息发布
        1.导包
        2.初始化ros节点
        3.创建发布者对象
        4.编写发布逻辑并发布数据
"""
def cb():
    rospy.loginfo("节点正在被关闭")

if __name__ == "__main__":
    #2.初始化ros节点
    """
    作用:ROS初始化函数

        参数：
            1.name              ---> 为节点命名（保证唯一性）
            2.argv=None         ---> 封装节点调用时传递的参数
            3.anonymous=False   ---> 可以为节点名称生成随即后缀,解决重名问题
        使用：
            1.argv的使用
              可以按照ROS中指定的语法格式传参,ROS可以解析并加以使用
            2.anonymous的使用
              可以设置为TRUE,节点名称后附加后缀避免重名问题
    """

    rospy.init_node("sanDai", anonymous=True)  #传入节点名称
    #3.创建发布者对象
    """
        内容:latch
            bool值,默认False
        作用:
            如果为True,可以将发布的最后一条数据保存,且后续的订阅对象连接时,会将该数据发送给订阅者
        使用:
            latch = True
    """
    # pub = rospy.Publisher("che", String, queue_size=10,latch=True)
    pub = rospy.Publisher("che", String, queue_size=10)
    #4.编写发布逻辑并发布数据
    #创建数据
    msg = String()
    #制定发布频率
    rate = rospy.Rate(1)
    #设置计数器
    count = 0
    #使用循环发布数据
    rospy.sleep(3)  #给发布者在master注册的时间，防止订阅者错失数据
    while not rospy.is_shutdown():
        count += 1
        if count <= 10:
            msg.data = "hello" + str(count)
            pub.publish(msg)
            rospy.loginfo("发布的数据是：%s", msg.data)
        
        else:
            rospy.on_shutdown(cb)
            rospy.signal_shutdown("关闭节点")
        rate.sleep()
    #发布数据
    pass