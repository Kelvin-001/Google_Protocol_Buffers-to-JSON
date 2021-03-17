#include <iostream>
#include <fstream>
#include "example.pb.h"

using namespace ucas;
using namespace std;
using namespace google::protobuf;

int main(int argc,char *argv[])
{
	Person p1;
	p1.set_name("Marry");
	p1.set_id(5001);
	p1.set_email("MarryLiu1998@163.com");

	Person_PhoneNumber *pn1 = p1.add_phone();
	pn1->set_number("13100000000");
	pn1->set_type(Person::HOME);

	Person_PhoneNumber *pn2 = p1.add_phone();
	pn2->set_number("15600000001");
	pn2->set_type(Person::MOBILE);
	
	

	Person p2;
	p2.set_name("zhangjie");
	p2.set_id(5002);
	p2.set_email("jasonzhang@163.com");

	Person_PhoneNumber *pn3 = p2.add_phone();
	pn3->set_number("10000");
	pn3->set_type(Person::MOBILE);


	
	Test t;
	t.set_name("zhang\n\nyuqi");
	t.set_age(22);
	t.add_phones("10010");
	t.add_phones("10086");

	Kinsfolk *kf1 = t.add_kinsfolks();
	kf1->set_name("father");
	kf1->set_age(52);
	Kinsfolk *kf2 = t.add_kinsfolks();
	kf2->set_name("mother");
	kf2->set_age(51);


	ofstream of("test_file/test0_01_input", ios::binary);
	string str1, str2,str3;

	p1.SerializeToString(&str1);
	p2.SerializeToString(&str2);
	t.SerializeToString(&str3);

	str1 = "^@UCAS@Person^" + str1;
	str2 = "^@UCAS@Person^" + str2;
	str3 = "^@UCAS@Test^"   + str3;
	//cout<<(int)(str1[str1.size()-1])<<"  "<<(int)(str3[str3.size()-1])<<"  "<<(int)(str2[str2.size()-1])<<endl;
	
	of<<str1<<str3<<str2;
	of.close();

	return 0;
}
