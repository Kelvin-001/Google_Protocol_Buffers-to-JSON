#include "dynamicParse.h"

int dynamicParseFromProtoFile(const string &filePath, const string &messageName, function<void(::google::protobuf::Message *msg)> callBack)
{
    //检查文件名是否合法
    //
    auto position = filePath.find_last_of('/');
    string path;
    string fileName;
    if (position == string::npos)
    {
        fileName = filePath;
    }
    else
    {
        path = filePath.substr(0, position);
        fileName = filePath.substr(position + 1);
    }

    ::google::protobuf::compiler::DiskSourceTree sourceTree;
    sourceTree.MapPath("", path);
    ::google::protobuf::compiler::Importer importer(&sourceTree, NULL);
    importer.Import(fileName);
    const ::google::protobuf::Descriptor *descriptor = importer.pool()->FindMessageTypeByName(messageName);
    if (!descriptor)
    {
        cout << "Can't get a descriptor from messageName : " << messageName << endl;
        return -1;
    }
    ::google::protobuf::DynamicMessageFactory factory;
    const ::google::protobuf::Message *message = factory.GetPrototype(descriptor);
    if (!message)
    {
        cout << "GetPrototype error." << endl;
        return -2;
    }
    ::google::protobuf::Message *msg = message->New();
    if (!msg)
    {
        cout << "New a empty message obejct error." << endl;
        return -3;
    }
    //callback
    callBack(msg);

    delete msg;

    return 0;
}
