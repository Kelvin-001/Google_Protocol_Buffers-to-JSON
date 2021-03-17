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
./generateTestData/test$1_01
echo  "Completed."

./main generateTestData/test$1_01.proto test_file/test$1_01_input test_file/test$1_01_output

