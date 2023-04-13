#! usr/bin/env python

# from sys import exception
import rospy
import tf2_ros
from tf2_geometry_msgs import tf2_geometry_msgs

from geometry_msgs.msg import TransformStamped

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
    # ps.header.stamp = rospy.Time(0.0)
    ps.header.stamp = rospy.Time.now()#因为是静态坐标系 所以可以now
    ps.header.frame_id = "son1"    
    ps.point.x = 1.0
    ps.point.y = 2.0
    ps.point.z = 3.0
    # 5.转换逻辑实现,调用tf封装的算法
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        try:
            """ 
                计算son1 son2的相对关系             
                
                参数1:目标坐标系 B
                参数2:被转换的源坐标系 A
                参数3:rospy.Time(0) 取间隔最短的两个坐标系关系帧(son1-world son2-world)计算相对关系
                返回值:son1 与 son2 之间的相对关系
            """
            ts = buffer.lookup_transform("son2","son1",rospy.Time(0))
            rospy.loginfo("son1 相对于 son2 的信息: 父级名称:%s, 子级名称:%s,偏移量(%2.f,%2.f,%2.f)",
            ts.header.frame_id,#son2
            ts.child_frame_id,#son1
            ts.transform.translation.x,
            ts.transform.translation.y,
            ts.transform.translation.z
            )
            #转换实现
            ps_out = buffer.transform(ps,"son2")
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