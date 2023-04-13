#! usr/bin/env python
import rospy
import tf2_ros

import tf.transformations

from geometry_msgs.msg import TransformStamped

""" 
    发布方：发布两个坐标系的相对关系（车辆底盘 --- base_link 雷达 --- laser）
    流程：
        1.导包；
        2.初始化节点
        3.创建发布对象
        4.组织被发布数据
        5.发布数据
        6.spin
"""

if __name__ == "__main__":
    # 2.初始化节点
    rospy.init_node("static_pub_p")
    # 3.创建发布对象
    pub = tf2_ros.StaticTransformBroadcaster()
    # 4.组织被发布数据
    ts = TransformStamped()
    #header
    ts.header.stamp = rospy.Time.now()
    ts.header.frame_id = "base_link"
    #child frame id
    ts.child_frame_id = "laser"
    #相对关系(偏移 四元数)
    #偏移
    ts.transform.translation.x = 0.2 
    ts.transform.translation.y = 0.0
    ts.transform.translation.z = 0.5
    #4-1先从欧拉角转换为四元数
    qtn = tf.transformations.quaternion_from_euler(0,0,0)
    #4-2再设置四元数
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.w = qtn[3]
    # 5.发布数据
    pub.sendTransform(ts)
    # 6.spin
    rospy.spin()    
