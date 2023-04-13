#! usr/bin/env python

import rospy

""" 
    参数服务器操作之查询_Python实现:    
    get_param(键,默认值)
        当键存在时，返回对应的值，如果不存在返回默认值
    get_param_cached
        与get_param一致，效率更高（从本地缓存读取数据 而不是通过ipc协议）
    get_param_names
        获取所有参数键的集合
    has_param
        判断是否包含某个键
    search_param
        查找并返回某个参数完整键名
"""

if __name__ == "__main__":
    rospy.init_node("get_param_p")
    #1.get_param
    radius = rospy.get_param("radius_p",0.5)
    radius2 = rospy.get_param("radius_p_xxx",0.5)

    rospy.loginfo("radius = %.2f",radius)
    rospy.loginfo("radius = %.2f",radius2) 

    #2.get_param_cached
    radius3 = rospy.get_param_cached("radius_p",0.6)
    radius4 = rospy.get_param_cached("radius_p_xxx",0.6)

    rospy.loginfo("radius = %.2f",radius3)
    rospy.loginfo("radius = %.2f",radius4)

    #3.get_param_names
    names = rospy.get_param_names()
    for name in names:
        rospy.loginfo("name = %s",name)

    #4.has_param
    flag1 = rospy.has_param("radius_p")
    if flag1:
        rospy.loginfo("radius_p存在")
    else:
        rospy.loginfo("radius_p不存在")

    flag2 = rospy.has_param("radius_xxx")
    if flag2:
        rospy.loginfo("radius_xxx存在")
    else:
        rospy.loginfo("radius_xxx不存在")

    #5 search_param
    key = rospy.search_param("radius_p")
    rospy.loginfo("key = %s",key)
    pass