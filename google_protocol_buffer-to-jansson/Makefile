GXX =g++ -std=c++11


.PHONY: generateTestData

all: lib  main generateTestData

lib: libpb2json.so libpb2json.a

libpb2json.so: pb2json.cc pb2json.h
	${GXX} -g -O3 -shared -Wall -fPIC -o libpb2json.so pb2json.cc -lprotobuf -ljansson
		

libpb2json.a: pb2json.o
	ar cr libpb2json.a pb2json.o
	 
main: main.cc utils.cc dynamicParse.cc libpb2json.a
	${GXX} -g -o main  main.cc  utils.cc  dynamicParse.cc  libpb2json.a  -I../  -lprotobuf -ljansson -lpthread
	 
generateTestData:
	cd generateTestData && make -f Makefile

pb2json.o:pb2json.cc

clean:
	rm -f *.o *.so *.a main
	cd generateTestData && make clean

install:
	install libpb2json.so /usr/local/lib/
	install libpb2json.a /usr/local/lib/
	cp -vf  pb2json.h /usr/local/include/
