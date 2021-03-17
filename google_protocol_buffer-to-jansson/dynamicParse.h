#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/compiler/importer.h>

#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//filePath proto文件名
//messageName proto文件里面的message， 格式package.Classname
//callBack, 创建好proto文件里面的messageName类之后执行的回调，可以在该回调里面操作数据

int dynamicParseFromProtoFile(const string &filePath, const string &messageName, function<void(::google::protobuf::Message *msg)> callBack);
