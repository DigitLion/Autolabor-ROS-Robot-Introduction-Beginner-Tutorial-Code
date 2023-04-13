
<!-- 
main函数 传入参数设置
 -->
rosrun plumbing_apis demo01_apis_pub_node _length:=2
rosparam list

<!-- 
重名节点
 -->
连续调用多次同名节点后：前一个同名节点会被关闭
[ WARN] [1676517558.481264029]: Shutdown request received.
[ WARN] [1676517558.481420743]: Reason given for shutdown: [[/erGouZi] Reason: new node registered with same name]
