#! usr/bin/env python

import rospy

""" 
    演示参数的新增与修改
    需求：在参数服务器中设置机器人属性:型号，半径
    实现：
        rospy.set_param()
"""

if __name__ == "__main__":
    #初始化ros节点
    rospy.init_node("param_set_p")
    #新增参数
    rospy.set_param("type_p","xiaoHuangChe")
    rospy.set_param("radius_p",0.15)
    #修改参数
    rospy.set_param("radius_p",0.2)
    pass