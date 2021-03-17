#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

string analyPackage(string protoPath);
vector<string> split(const string &str, const string &delim);
void trim(string &str);
string analyMessage(string protoPath);
string regexClassName(string p_str);