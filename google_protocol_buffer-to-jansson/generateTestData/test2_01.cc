#include <iostream>
#include <fstream>
#include "test2_01.pb.h"

using namespace ucas;
using namespace std;
using namespace google::protobuf;

int main(int argc,char *argv[])
{
	Person p1;
	p1.set_id(0);

	p1.set_name("Marry");
	p1.set_email("MarryLiu1998@163.com");

	Person_PhoneNumber *pn1 = p1.add_phone();
	pn1->set_number("13100000000");
	pn1->set_type(Person::HOME);

	Person_PhoneNumber *pn2 = p1.add_phone();
	pn2->set_number("15600000001");
	pn2->set_type(Person::MOBILE);

        xxx1 t1;
        xxx2 t2;
        xxx3 t3;
        xxx4 t4;
        xxx5 t5;
        xxx6 t6;
        xxx7 t7;
        xxx8 t8;
        xxx9 t9;
        xxx10 t10;
        xxx11 t11;
        xxx12 t12;
        xxx13 t13;
        xxx14 t14;
        xxx15 t15;
        xxx16 t16;
        xxx17 t17;
        xxx18 t18;
        xxx19 t19;
        xxx20 t20;
        xxx21 t21;
        xxx22 t22;
        xxx23 t23;
        xxx24 t24;
        xxx25 t25;
        xxx26 t26;
	UCASUCAS ucas1;
	UCAS2 ucas2;
	UCAS3 ucas3;
	UCAS4 ucas4;

	t1.set_type("optional");
	t14.set_id(1400000);

	t10.set_id(100000);
	t20.set_id(200000);
	t24.set_id(240000);

	ucas1.set_id(1);
        ucas1.set_name("^UCAS@UCAS");
        ucas1.set_age(21);
        ucas1.add_phones("10010");
        ucas1.add_phones("10086");

	ucas2.set_id(2);
	ucas2.set_name("^UCAS");
//	ucas2.set_name("2222");
        ucas2.set_age(22);
        ucas2.add_phones("10010");
        ucas2.add_phones("10086");

	ucas3.set_id(3);
        //ucas3.set_name("@UCAS");
        ucas3.set_name("3333");
        ucas3.set_age(23);
        ucas3.add_phones("10010");
        ucas3.add_phones("10086");

	ucas4.set_id(77);
        ucas4.set_name("UCAS^");
        //ucas4.set_name("4444");
        ucas4.set_age(24);
        ucas4.add_phones("10010");
        ucas4.add_phones("10086");

	ofstream of("test_file/test2_01_input", ios::binary);
        string str0;
        p1.SerializeToString(&str0);

	string str1;
        t1.SerializeToString(&str1);
	string str2;
        t2.SerializeToString(&str2);
	string str3;
        t3.SerializeToString(&str3);
	string str4;
        t4.SerializeToString(&str4);
	string str5;
        t5.SerializeToString(&str5);
	string str6;
        t6.SerializeToString(&str6);
	string str7;
        t7.SerializeToString(&str7);
	string str8;
        t8.SerializeToString(&str8);
	string str9;
        t9.SerializeToString(&str9);
	string str10;
        t10.SerializeToString(&str10);
	string str11;
        t11.SerializeToString(&str11);
	string str12;
        t12.SerializeToString(&str12);
	string str13;
        t13.SerializeToString(&str13);
	string str14;
        t14.SerializeToString(&str14);
	string str15;
        t15.SerializeToString(&str15);
        string str16;
        t16.SerializeToString(&str16);
        string str17;
        t17.SerializeToString(&str17);
        string str18;
        t18.SerializeToString(&str18);
        string str19;
        t19.SerializeToString(&str19);
        string str20;
        t20.SerializeToString(&str20);
        string str21;
        t21.SerializeToString(&str21);
        string str22;
        t22.SerializeToString(&str22);
        string str23;
        t23.SerializeToString(&str23);
        string str24;
        t24.SerializeToString(&str24);
        string str25;
        t25.SerializeToString(&str25);
        string str26;
        t26.SerializeToString(&str26);


        string str27;
        ucas1.SerializeToString(&str27);
        string str28;
        ucas2.SerializeToString(&str28);
        string str29;
        ucas3.SerializeToString(&str29);
        string str30;
        ucas4.SerializeToString(&str30);

        str0 = "^@UCAS@Person^" + str0;
        str1 = "^@UCAS@xxx1^" + str1;
        str2 = "^@UCAS@xxx2^" + str2;
        str3 = "^@UCAS@xxx3^" + str3;
        str4 = "^@UCAS@xxx4^" + str4;
        str5 = "^@UCAS@xxx5^" + str5;
        str6 = "^@UCAS@xxx6^" + str6;
        str7 = "^@UCAS@xxx7^" + str7;
        str8 = "^@UCAS@xxx8^" + str8;
        str9 = "^@UCAS@xxx9^" + str9;
	str11 = "^@UCAS@xxx1^" + str11;
        str12 = "^@UCAS@xxx1^" + str12;
        str13 = "^@UCAS@xxx1^" + str13;
        str14 = "^@UCAS@xxx1^" + str14;//14 use message xxx1
        str15 = "^@UCAS@xxx1^" + str15;
        str16 = "^@UCAS@xxx1^" + str16;
        str17 = "^@UCAS@xxx1^" + str17;
        str18 = "^@UCAS@xxx1^" + str18;
        str19 = "^@UCAS@xxx1^" + str19;
        str21 = "^@UCAS@xxx21^" + str21;
        str22 = "^@UCAS@xxx22^" + str22;
        str23 = "^@UCAS@xxx23^" + str23;
        str25 = "^@UCAS@xxx25^" + str25;
        str26 = "^@UCAS@xxx26^" + str26;

        str10 = "^@UCAS@xxx10^" + str10;
        str20 = "^@UCAS@xxx20^" + str20;
        str24 = "^@UCAS@xxx24^" + str24;
        
	str27 = "^@UCAS@UCASUCAS^" + str27;
        str28 = "^@UCAS@UCAS2^" + str28;
        str29 = "^@UCAS@UCAS3^" + str29;
        str30 = "^@UCAS@UCAS4^" + str30;
        
      	of<<str0<<str1<<str2<<str3<<str4<<str5<<str6<<str7<<str8<<str9<<str10<<str11<<str12<<str13<<str14<<str15<<str16<<str17<<str18<<str19<<str20<<str21<<str22<<str23<<str24<<str25<<str26<<str27<<str28<<str29<<str30;
        of.close();
		
/*
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


	ofstream of("test_file/0_input", ios::binary);
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
*/
	return 0;
}
