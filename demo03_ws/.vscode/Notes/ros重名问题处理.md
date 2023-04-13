
 <!-- ros中处理同名问题：命名空间/名称重映射为主 -->
 1.工作空间重名：尽量避免
 2.节点重名：
    2-1.rosrun命令
        1#为节点起别名
        rosrun turtlesim  turtlesim_node __name:=t1
        rosrun turtlesim  turtlesim_node /turtlesim:=t1(不适用于python)

        2# 名称重映射
        rosrun turtlesim  turtlesim_node __name:=t2
        rosrun turtlesim  turtlesim_node /turtlesim:=t2(不适用于python)
    2-2.launch文件
        src/rename01_node/launch/start_turtle.launch
    2-3.编码实现
        ros::init(argc,argv,"zhangsan",ros::init_options::AnonymousName);会在名称后面添加时间戳

        std::map<std::string, std::string> map;
        map["__ns"] = "xxxx";
        ros::init(map,"wangqiang");

 3.话题重名：
    3-1.rosrun命令
        二选一
        rosrun teleop_twist_keyboard teleop_twist_keyboard.py /cmd_vel:=/turtle1/cmd_vel
        rosrun turtlesim turtlesim_node /turtle1/cmd_vel:=/cmd_vel
    3-2.launch文件
        

    3-3.编码实现
 4.参数重名：
    4-1.rosrun命令
    4-2.launch文件
    4-3.编码实现