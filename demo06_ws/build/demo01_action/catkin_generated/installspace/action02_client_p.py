#! usr/bin/env python
import rospy
import actionlib
from demo01_action.msg import *
""" 
    需求:
        创建两个ROS节点，服务器和客户端，
        客户端可以向服务器发送目标数据N（一个整型数据）
        服务器会计算1到N之间所有整数的和，这是一个循环累加的过程，返回给客户端，
        这是基于请求响应模式的，
        又已知服务器从接收到请求到产生响应是一个耗时操作，每累加一次耗时0.1s，
        为了良好的用户体验，需要服务器在计算过程中，
        每累加一次，就给客户端响应一次百分比格式的执行进度，使用action实现。
    流程：
        1.导包
        2.初始化ROS节点
        3.创建action客服端对象（等待服务启动）
        4.发送请求
            a.激活处理； --- 回调函数
            b.处理连续反馈 --- 回调函数1
            c.处理最终响应 --- 回调函数2
        6.spin()回旋
"""
    ## @param done_cb Callback that gets called on transitions to
    ## Done.  The callback should take two parameters: the terminal
    ## state (as an integer from actionlib_msgs/GoalStatus) and the
    ## result.
    ##
    ## @param active_cb   No-parameter callback that gets called on transitions to Active.
    ##
    ## @param feedback_cb Callback that gets called whenever feedback
    ## for this goal is received.  Takes one parameter: the feedback.
def done_cb(status,result):
    if status == actionlib.GoalStatus.SUCCEEDED:
        rospy.loginfo("最终响应结果：%d",result.result)
    else:
        rospy.loginfo("响应失败...")
    pass

def active_cb():
    rospy.loginfo("已建立连接...")
    pass

def feedback_cb(feedback : AddIntsFeedback):
    rospy.loginfo("当前进度：%.2f",feedback.progress_bar)
    pass


if __name__ == "__main__":
    # 2.初始化ROS节点
    rospy.init_node("action_client_p")
    # 3.创建action客服端对象（等待服务启动）
    client = actionlib.SimpleActionClient("addInts",AddIntsAction)
    rospy.loginfo("等待服务端开启...")
    client.wait_for_server()
    # 4.发送请求
    """ 
    send_goal(goal: Any, done_cb: Any | None = None, active_cb: Any | None = None, feedback_cb: Any | None = None) -> None
    """
    # 参数1:目标值
    # 参数2:结果回调
    # 参数3:连接被激活的回调
    # 参数4:连续反馈回调
    goal_obj = AddIntsGoal()
    goal_obj.num = 10

    client.send_goal(goal_obj,done_cb,active_cb,feedback_cb)
    #     a.激活处理； --- 回调函数
    #     b.处理连续反馈 --- 回调函数1
    #     c.处理最终响应 --- 回调函数2
    # 6.spin()回旋
    rospy.spin()
    pass