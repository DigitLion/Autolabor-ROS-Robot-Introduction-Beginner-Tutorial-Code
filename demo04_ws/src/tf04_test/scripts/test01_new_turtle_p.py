#! usr/bin/env python

import rospy
from turtlesim.srv import Spawn,SpawnRequest,SpawnResponse

"""
    需求:向服务端发送请求，生成新乌龟
        话题:/spawn
        消息:turtlesim/spawn
    
    1.导包
    2.初始化ROS节点
    3.创建服务端对象
    4.组织数据并发送
    5.处理响应
"""

if __name__ == "__main__":
    # 2.初始化ROS节点
    rospy.init_node("service_call_p")
    # 3.创建服务端对象
    client = rospy.ServiceProxy("/spawn",Spawn)
    # 4.组织数据并发送
    # 4-1.组织数据
    request = SpawnRequest()
    request.x = 4.5
    request.y = 2.0
    request.theta = 3.14
    request.name = "turtle2"
    # 4-2.判断服务器状态
    client.wait_for_service()
    # 5.处理响应
    try:
        response = client.call(request)
        rospy.loginfo("乌龟%s生成成功",response.name)
    except Exception as e:
        rospy.logerr("请求处理异常")

    pass