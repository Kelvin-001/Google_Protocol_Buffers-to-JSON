#include "utils.h"
#include <stdio.h>

string analyPackage(string protoPath)
{

    string content = "";
    string line = "";

    ifstream ifs(protoPath);

    if (ifs.bad())
    {
        return "-1";
    }

    string substr = "//";
    string::size_type position;

    while (getline(ifs, line))
    {
        position = line.find(substr);
        if (position != line.npos)
        {
            line = line.substr(0, position);
            //cout<<"delete explanatory note : "<<line<<endl;
        }
        content = content + line;
    }

    string packageName = "";
    regex reg("package\\s+.*?\\s*;");
    smatch m;
    auto ret = regex_search(content, m, reg);

    if (ret)
    {
        //cout << "package regex_search results :" <<m.size()<<"  "<< m[0] << "  " << m[1] << endl;
        string temp = m[0];
        trim(temp);
        vector<string> res = split(temp, " ;\t");
        trim(res[1]);
        packageName = res[1];
    }
    //cout<<"packageName = "<<packageName<<endl;
    return packageName;
}


string analyMessage(string protoPath)
{
    string content = "";
    string line = "";

    ifstream ifs(protoPath);

    if (ifs.bad())
    {
        return "-1";
    }

    string substr = "//";
    string::size_type position;

    while (getline(ifs, line))
    {
        position = line.find(substr);
        if (position != line.npos)
        {
            line = line.substr(0, position);
            //cout<<"delete explanatory note : "<<line<<endl;
        }
        content = content + line;
    }

    string messageName = "";
    regex reg("message\\s+.*?\\s*\\{");
    smatch m;
    auto ret = regex_search(content, m, reg);
    //如果没有消息没有分隔符，即没有类名，那么默认proto文件中的第一个message名为类名
    //If there is no message and no separator, that is, there is no class name, 
    //the first message in the default proto file is the class name
    if (ret)
    {
        //cout << "message regex_search results :" <<m.size()<<"  "<<m[0] << "  " << m[1] << endl;
        string temp = m[0];
        trim(temp);
        vector<string> res = split(temp, " {\t");
        trim(res[1]);
        messageName = res[1];
    }
    return messageName;
}


string regexClassName(string p_str)
{
    string className = "";
    regex reg("\\^@UCAS@(.*)\\^");
    smatch m;
    auto ret = regex_search(p_str, m, reg);
    if (ret)
    {
        string temp = m[0];
        temp = split(temp, "@^")[1];
        trim(temp);
        className = temp;
    }
    //cout<<"className: "<<className<<endl;
    return className;
}


vector<string> split(const string &str, const string &delim)
{
    vector<string> res;
    if ("" == str)
        return res;
    //先将要切割的字符串从string类型转换为char*类型
    char *strs = new char[str.length() + 1]; //不要忘了
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p)
    {
        string s = p;     //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }

    return res;
}


void trim(string &str)
{
    if (str.empty())
    {
        return;
    }
    str.erase(0, str.find_first_not_of(" "));
    str.erase(0, str.find_first_not_of("\t"));
    str.erase(str.find_last_not_of(" ") + 1);
    str.erase(str.find_last_not_of("\t") + 1);
}
