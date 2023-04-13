#! /usr/bin/env python

#现象：不配置cmakelist执行python出现异常：
# /usr/bin/env: “python”: 没有那个文件或目录
#原因：当前noetic使用的是python3
#解决：
#   1.直接声明解释器为pyhon3(不建议):
#        /usr/bin/env python3
#   2.软链接：将python链接到python3：
#       sudo ln -f /usr/bin/python3 /usr/bin/python


#packages
import rospy
#entry
if __name__ == "__main__":
    #int ros
    rospy.init_node("hello_p2")
    #log
    rospy.loginfo("hello vscode! 这里是派森2！")
