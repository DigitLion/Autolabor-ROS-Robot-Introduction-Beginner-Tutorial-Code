#! usr/bin/env python
import rospy

""" 
    演示参数删除：
        delete_param()
"""

if __name__ == "__main__":
    #初始化节点
    rospy.init_node("dle_param_p")
    
    flag1 = rospy.has_param("radius_p")
    if flag1:
        rospy.loginfo("radius_p存在")
        #删除参数
        rospy.delete_param("radius_p")
    else:
        rospy.loginfo("radius_p不存在")
        rospy.set_param("radius_p",0.15)
    
    try:
        #删除参数
        rospy.delete_param("radius_p")
    except Exception as e:
            rospy.loginfo("被删除的参数不存在")

    flag1 = rospy.has_param("radius_p")
    radius = rospy.get_param("radius_p",0.5)
    if flag1:
        rospy.loginfo("radius_p存在")
        rospy.loginfo("radius = %.2f",radius)
    else:
        rospy.loginfo("radius_p不存在")
        rospy.loginfo("radius = %.2f",radius)
    pass