#! usr/bin/env python

import rospy
from turtlesim.msg import Pose

""" 
    需求：订阅并输出乌龟位姿信息

    1.导包
    2.初始化ROS节点
    3.创建订阅对象
    4.使用回调函数处理订阅的信息
    5.spin
"""

def doPose(pose:Pose):
    rospy.loginfo("P->乌龟位姿信息:坐标(%.2f,%.2f),朝向:%.2f,线速度:%.2f,角速度:%.2f",
                  pose.x,pose.y,pose.theta,pose.linear_velocity,pose.angular_velocity)

if __name__ == "__main__":
    # 2.初始化ROS节点
    rospy.init_node("sub_pose_p")
    # 3.创建订阅对象
    sub = rospy.Subscriber("/turtle1/pose",Pose,doPose,queue_size=10)
    # 4.使用回调函数处理订阅的信息
    # 5.spin
    rospy.spin()
    pass