#! usr/bin/env python

import rospy

from turtlesim.msg import Pose
import tf2_ros
from geometry_msgs.msg import TransformStamped
from turtlesim.msg import Pose

import tf.transformations

import sys

""" 
    发布方:需要订阅乌龟位姿信息,并转换成坐标系的相对关系,最后发布
    准备:
        1.乌龟位姿话题: /turtle1/pose
        2.消息类型:turtlesim/Pose
    流程:
        1.导包
        2.初始化ROS节点
        3.创建订阅对象
        4.回调函数处理订阅到的消息(核心)
        5.spin()
"""
#接收乌龟名称变量
turtle_name = ""

def doPose(pose:Pose):
    #1.创建发布坐标系相对关系的对象
    pub = tf2_ros.TransformBroadcaster()
    #2.将pose转换成坐标系相对关系消息
    ts = TransformStamped()
    ts.header.frame_id = "world"
    ts.header.stamp = rospy.Time.now()
    ts.header.seq = 103
    #修改2:子集坐标系名称
    ts.child_frame_id = turtle_name
    #子级坐标系相对于父级坐标系的偏移两
    ts.transform.translation.x = pose.x
    ts.transform.translation.y = pose.y
    ts.transform.translation.z = 0
    #从欧拉角转换四元数
    """ 
        乌龟是2D的,不存在X方向的roll,Y上的yaw,只有z上的pitch
    """
    qtn = tf.transformations.quaternion_from_euler(0,0,pose.theta)
    #四元数
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.w = qtn[3]
    #3.发布
    pub.sendTransform(ts)
    pass

if __name__ == "__main__":
    
    # 2.初始化ROS节点
    rospy.init_node("dynamic_pub_p")
    # 3.创建订阅对象
    
    #解析传入的参数(现在传入几个参数?1.文件全路径+传入参数+节点名称+日志输出文件路径)
    if len(sys.argv) != 4:
        rospy.loginfo("参数数目不对")
        sys.exit(1)
    else:
        turtle_name = sys.argv[1]
        pass
    
    # 修改1：话题名称
    sub = rospy.Subscriber(turtle_name + "/pose",Pose,doPose,queue_size = 100)
    # 4.回调函数处理订阅到的消息(核心)
    # 5.spin()
    rospy.spin()
    pass