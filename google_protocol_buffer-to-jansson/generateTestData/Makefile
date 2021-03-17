GXX =g++ -std=c++11
all: example.pb.cc test_example test1_01.pb.cc test1_01 test2_01.pb.cc test2_01 test3_01.pb.cc test3_01 test4_01.pb.cc test4_01 test5_01.pb.cc test5_01 test6_01.pb.cc test6_01

example.pb.cc example.pb.h:example.proto
	protoc --cpp_out=./ example.proto

test_example: test_example.cc example.pb.cc example.pb.h
	${GXX} -g -o test_example test_example.cc example.pb.cc -lprotobuf -lpthread

test1_01.pb.cc test1_01.pb.h:test1_01.proto
	protoc --cpp_out=./ test1_01.proto

test1_01: test1_01.cc test1_01.pb.cc test1_01.pb.h
	${GXX} -g -o test1_01 test1_01.cc test1_01.pb.cc -lprotobuf -lpthread

test2_01.pb.cc test2_01.pb.h:test2_01.proto
	protoc --cpp_out=./ test2_01.proto

test2_01: test2_01.cc test2_01.pb.cc test2_01.pb.h
	${GXX} -g -o test2_01 test2_01.cc test2_01.pb.cc -lprotobuf -lpthread

test3_01.pb.cc test3_01.pb.h:test3_01.proto
	protoc --cpp_out=./ test3_01.proto

test3_01: test3_01.cc test3_01.pb.cc test3_01.pb.h
	${GXX} -g -o test3_01 test3_01.cc test3_01.pb.cc -lprotobuf -lpthread

test4_01.pb.cc test4_01.pb.h:test4_01.proto
	protoc --cpp_out=./ test4_01.proto

test4_01: test4_01.cc test4_01.pb.cc test4_01.pb.h
	${GXX} -g -o test4_01 test4_01.cc test4_01.pb.cc -lprotobuf -lpthread

test5_01.pb.cc test5_01.pb.h:test5_01.proto
	protoc --cpp_out=./ test5_01.proto

test5_01: test5_01.cc test5_01.pb.cc test5_01.pb.h
	${GXX} -g -o test5_01 test5_01.cc test5_01.pb.cc -lprotobuf -lpthread

test6_01.pb.cc test6_01.pb.h:test6_01.proto
	protoc --cpp_out=./ test6_01.proto

test6_01: test6_01.cc test6_01.pb.cc test6_01.pb.h
	${GXX} -g -o test6_01 test6_01.cc test6_01.pb.cc -lprotobuf -lpthread

clean:
	rm -f test_example example.pb.h example.pb.cc
	rm -f test_example test*_01 test*_01.pb.cc test*_01.pb.h ../test_file/test*_01_input ../test_file/test*_01_output

