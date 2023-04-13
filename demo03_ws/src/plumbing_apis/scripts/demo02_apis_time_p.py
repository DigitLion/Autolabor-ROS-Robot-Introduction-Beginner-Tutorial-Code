#! usr/bin/env python

import rospy

""" 
    需求:
        1.演示时间相关操作(获取当前时刻+设置指定时刻)

        2.程序执行中停顿5s

        3.获取程序开始执行的时刻,已知持续运行时间,计算程序结束时间
        
        4.创建定时器,实现类似ros::Rate的功能(某个时间间隔执行某操作)

"""

if __name__ == "__main__":
    # 1.演示时间相关操作(获取当前时刻+设置指定时刻)
    rospy.init_node("hello_time")
    #获取时刻
    right_now = rospy.Time.now() #获取当前时刻(now()被调用执行的时刻,参考1940.1.1 00:00:00)封装到对象
    rospy.loginfo("当前时刻:%.2f",right_now.to_sec())
    rospy.loginfo("当前时刻:%d",right_now.secs)#整型字段

    #设置指定
    time1 = rospy.Time(100)#
    time2 = rospy.Time(100,312345678)#
    rospy.loginfo("指定时刻1:%.2f",time1.to_sec())
    rospy.loginfo("指定时刻2:%.2f",time2.to_sec())

    #从某个时间值获取时间对象
    time3 = rospy.Time.from_sec(210.12)
    rospy.loginfo("指定时刻3:%.2f",time3.to_sec())

    # 2.程序执行中停顿5s
    rospy.loginfo("休眠前-----------------------")
    #2-1.封装持续对象
    du = rospy.Duration(5,0)
    #2-2.持续时间休眠
    # du.sleep() 此语句异常
    # rospy.sleep(du)
    rospy.loginfo("休眠后-----------------------")

    # 3.获取程序开始执行的时刻,已知持续运行时间,计算程序结束时间
    #3-1.获取一个时刻t1
    t1 = rospy.Time.now()
    #3-2.设置持续时间du1
    du1 = rospy.Duration(5)
    #3-3.t2 = t1 + du1
    t2 = t1 + du1
    rospy.loginfo("开始时刻:%.2f",t1.to_sec())
    rospy.loginfo("结束时刻:%.2f",t2.to_sec())
    du2 = du + du1
    rospy.loginfo("持续时间叠加:%.2f",du2.to_sec())

    # t2 = right_now + t1 # 时间时刻之间没有加法运算

    # 4.创建定时器,实现类似ros::Rate的功能(某个时间间隔执行某操作)
    """
        Constructor.
        @param period: desired period between callbacks
        @type  period: rospy.Duration
        @param callback: callback to be called
        @type  callback: function taking rospy.TimerEvent
        @param oneshot: if True, fire only once, otherwise fire continuously until shutdown is called [default: False]
        @type  oneshot: bool
        @param reset: if True, timer is reset when rostime moved backward. [default: False]
        @type  reset: bool
    """
    def doMsg(event):
        rospy.loginfo("=====================")
        rospy.loginfo("%.2f",event.current_real.to_sec())

    timer = rospy.Timer(rospy.Duration(2),doMsg,True)

    rate = rospy.Rate(0.5)
    rospy.spin()
    pass