#!/bin/bash
if [ ! -x "generateTestData/test_example" ]
then
	echo "Object doesn't exist,please run make first"
	exit 1
fi
if [ ! -x "main" ]
then
	echo "Object doesn't exist,please run make first"
	exit 1
fi

echo "Generating test data..."
./generateTestData/test_example
echo  "Completed."

./main generateTestData/example.proto test_file/test0_01_input test_file/test0_01_output


