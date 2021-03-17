#include <iostream>
#include <fstream>
#include "test5_01.pb.h"

using namespace ucas;
using namespace std;
using namespace google::protobuf;

int main(int argc,char *argv[])
{
	ofstream of("test_file/test5_01_input", ios::binary);
	TestMessage TM1;
	TM1.set_optional_int32(321);
	TM1.set_optional_int64(641);
	TM1.set_optional_uint32(320);
	TM1.set_optional_uint64(640);
	TM1.add_repeated_int32(111111);
	TM1.add_repeated_int32(sizeof(uint32));
	TM1.add_repeated_int32(222222);
	TM1.add_repeated_int32(sizeof("0123456789"));
	TM1.add_repeated_string("repeated_string_1111");
	TM1.add_repeated_string("repeated_string_2222");
	TM1.add_repeated_enum(ZERO);
	TM1.add_repeated_enum(ONE);
	TM1.set_oneof_string("oneof_string111");
	int num = 100000;

        for(int i = 0; i < num; ++i){
	    TM1.add_repeated_fixed32(4444);
	}

	TM1.add_repeated_string("finish");
	//CHECK(TM1.has_oneof_string());
	
	string str_TM1;
        TM1.SerializeToString(&str_TM1);

  //      str1 = "^@UCAS@Person^" + str1;
        str_TM1 = "^@UCAS@TestMessage^" + str_TM1;
        of<<str_TM1;

	for(int i = 0; i < num; ++i){
	    TestMessage TMI;
            TMI.set_optional_int32(123);
            //TMI.set_optional_int32(i); use i wrong
	    string str_TMI;
            str_TMI = "^@UCAS@TestMessage^" + str_TMI;
	    of<<str_TMI;
        }

        of.close();
		
	return 0;
}
