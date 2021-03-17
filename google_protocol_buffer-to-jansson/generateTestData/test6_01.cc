#include <iostream>
#include <fstream>
#include "test6_01.pb.h"

using namespace ucas;
using namespace std;
//using namespace google::protobuf;

int main(int argc,char *argv[])
{
	TestMessage TM1;
	TM1.set_optional_int32(321);
	TM1.set_optional_int64(641);
	TM1.set_optional_uint32(320);
	TM1.set_optional_uint64(640);
	TM1.add_repeated_int32(323232);
	TM1.add_repeated_string("repeated_string_1111");
	TM1.add_repeated_string("repeated_string_2222");
	TM1.add_repeated_enum(ZERO);
	TM1.add_repeated_enum(ONE);
	TM1.set_oneof_string("oneof_string111");
	//CHECK(TM1.has_oneof_string());

/*
	Person_PhoneNumber *pn1 = p1.add_phone();
	pn1->set_number("13100000000");
	pn1->set_type(Person::HOME);

	Person_PhoneNumber *pn2 = p1.add_phone();
	pn2->set_number("15600000001");
	pn2->set_type(Person::MOBILE);


	ofstream of("test_file/test6_01_input", ios::binary);
        string str1;
        p1.SerializeToString(&str1);
*/
	ofstream of("test_file/test6_01_input", ios::binary);
	string str_TM1;
        TM1.SerializeToString(&str_TM1);

  //      str1 = "^@UCAS@Person^" + str1;
        str_TM1 = "^@UCAS@TestMessage^" + str_TM1;

        of<<str_TM1;
        of.close();
		
	return 0;
}
