#include "dynamicParse.h"
#include "pb2json.h"
#include "utils.h"

string json_str = "";
vector<string> vec;

int dynamicParse(vector<string> &vec, string protoPath, string outputPath, string packageName)
{
    ofstream ofs(outputPath);
    int totalMessageNum = vec.size();
    double factor = 0.1;
    for (int i = 0; i < totalMessageNum; ++i)
    {
        if(totalMessageNum >=10 && i == int(totalMessageNum * factor))
        {
            cout<<"complete "<<factor*100<<"% ..."<<endl;
            factor += 0.1;
        }
        string pbBinarystr = vec[i];
        string className = regexClassName(pbBinarystr);
        if (className != "")
        {
            //分隔符除了类名，还有8个字符 "^@UCAS@XXXXXX^"
            //The separator has 8 bytes in addition to the message name
            pbBinarystr = pbBinarystr.substr(className.size() + 8);
        }
        else
        {
            className = analyMessage(protoPath);
            if (className == "")
            {
                cout << "Can't find a message type." << endl;
                return -1;
            }
        }

        string packageClassName = className;
        if (packageName != "")
        {
            packageClassName = packageName + "." + packageClassName;
        }

        //从文件中protoPath中的packageClassName("packageName.className")类，解析类的序列化二进制
        //并输出序列化后的"packageName.className"的信息
        if (dynamicParseFromProtoFile(protoPath, packageClassName, [pbBinarystr](::google::protobuf::Message *msg) {
                if (msg->ParseFromString(pbBinarystr))
                {
                    char *json = pb2json(msg);
                    json_str = (string)json;
                    free(json);
                }
            }))
        {
            cout << "Dynamic parse error." << endl;
            return -2;
        }
        ofs << json_str << endl;
        json_str = "";

    }

    //cout<<"output_json"<<json_str<<endl;
    ofs.close();
    return 0;
}
vector<string> readBinaryData(const string &filePath)
{
    int length;
    char *buffer;
    ifstream fin(filePath, ios::in | ios::binary);
    if (fin.bad())
    {
        return vec;
    }
    //一次性读取整个文件 Read entire file at once
    fin.seekg(0, std::ios::end); // go to the end
    length = fin.tellg();        // report location (this is the length)
    fin.seekg(0, std::ios::beg); // go back to the beginning
    buffer = new char[length];   // allocate memory for a buffer of appropriate dimension
    fin.read(buffer, length);    // read the whole file into the buffer
    fin.close();                 // close file handle

    string str = "";
    double factor = 0.1;
    //cout<<"total file length:"<<length<<endl;
    for (int i = 0; i < length; i++)
    {
        if(i == int(length * factor))
        {
            cout<<"complete "<<factor*100<<"% ..."<<endl;
            factor += 0.1;
        }
        //cout << i << " " << (int)buffer[i] << "  " << buffer[i] << endl;
        //如果连续匹配分隔符的前7个字符，则认为是一条新的message数据
        
        //If the first seven characters of the separator are matched consecutively, it is considered a new message data.
        if (i < length - 6 && buffer[i] == '^' && buffer[i + 1] == '@' && buffer[i + 2] == 'U' && buffer[i + 3] == 'C' && buffer[i + 4] == 'A' && buffer[i + 5] == 'S' && buffer[i + 6] == '@')
        {
            if (str.size() == 0)
            {
                str = "^";
                continue;
            }

            vec.push_back(str);
            //cout << "<START>" << str << "<END>" << endl;
            str = "^";
        }
        else
        {
            str = str + buffer[i];
        }
    }
    if (str != "")
    {
        //cout << "<START>" << str << "<END>" << endl;
        vec.push_back(str);
    }

    return vec;
}

int main(int argc, char **argv)
{

    if (argc != 4)
    {
        cout << "Parameters number error." << endl;
        return -1;
    }
    string protoPath = argv[1];
    string binaryData = argv[2];
    string outputPath = argv[3];
    cout<<"Reading binary data..."<<endl;
    vector<string> vec = readBinaryData(binaryData);
    if (vec.size() == 0)
    {
        cout << "BinaryData file path error." << endl;
        return -2;
    }else
    {
         cout<<"Completed."<<endl;
    }
    
    string package = analyPackage(protoPath);
    if (package == "-1")
    {
        cout << ".proto file path error." << endl;
        return -4;
    }
    
    cout<<"Parsing binary protobuf data to json..."<<endl;
    if (dynamicParse(vec, protoPath, outputPath, package))
    {
        return -5;
    }
    cout<<"Completed."<<endl;
    return 0;
}
