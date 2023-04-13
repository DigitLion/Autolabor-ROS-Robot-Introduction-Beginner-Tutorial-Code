#! usr/bin/env python

# from sys import exception
import rospy
import tf2_ros
from tf2_geometry_msgs import tf2_geometry_msgs

""" 
    订阅方：订阅坐标变换消息、传入被转换的座标点，调用转换算法（已经封装）
    
    流程:
        1.导包
        2.初始化
        3.创建订阅对象
        4.组织被转换座标点
        5.转换逻辑实现,调用tf封装的算法
        6.输出结果

"""

if __name__ == "__main__":
    # 2.初始化
    rospy.init_node("dynamic_sub_p")
    # 3.创建订阅对象
    # 3-1.创建缓存对象
    buffer = tf2_ros.Buffer()
    # 3-2.创建订阅对象,将缓存传入
    sub = tf2_ros.TransformListener(buffer)
    # 4.组织被转换座标点
    ps = tf2_geometry_msgs.PointStamped()
    ps.header.seq = 101
    ps.header.stamp = rospy.Time(0.0)#修改时间为0而不是now
    ps.header.frame_id = "turtle1"
    
    ps.point.x = 2.0
    ps.point.y = 3.0
    ps.point.z = 5.0
    # 5.转换逻辑实现,调用tf封装的算法
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        try:
            #转换实现
            """ 
                参数1:被转换座标点
                参数2:目标坐标系
                返回值:转换后的座标点
                
                PS:
                问题:抛出异常:world不存在
                原因:转换函数调用时可能还没有订阅到坐标系的相对信息
                解决:try Exception 捕获异常(使得程序认为已经解决异常而继续运行)
            """
            ps_out = buffer.transform(ps,"world")    
            rospy.loginfo("转换后的坐标(%.2f,%.2f,%.2f),参考的坐标系:%s",
                        ps_out.point.x,
                        ps_out.point.y,
                        ps_out.point.z,
                        ps_out.header.frame_id
                        )
        except Exception as e:
            rospy.logwarn("错误提示:%s",e)            
    rate.sleep()
    # 7.spin()
    rospy.spin() 