#! usr/bin/env python
import rospy

if __name__ == "__main__":
    #演示日志函数
    rospy.init_node("hello_log")
    rospy.logdebug("DEBUG消息")
    rospy.loginfo("INFO消息")
    rospy.logwarn("WARN消息")
    rospy.logerr("ERROR消息")
    rospy.logfatal("FATAL消息")


    pass