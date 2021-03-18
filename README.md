# Google_Protocol_Buffers-to-JSON

使用方法：
这里假设你已经安装好了protobuf, 2.X与3.X均可。
#### 1. 安装jansson
 >wget "http://www.digip.org/jansson/releases/jansson-2.12.tar.gz "  
 >tar -zxvf jansson-2.12.tar.gz  
 >cd jansson-2.12  
 >./configure  
 >make    
 >sudo make install  

#### 2. 安装 pb2json
 >make   
 >sudo make install  

#### 3. 测试运行
 >./runtest.sh

#### 4.清理
 >make clean


#### main函数的命令行参数：proto文件路径 二进制文件路径  输出文件路径
