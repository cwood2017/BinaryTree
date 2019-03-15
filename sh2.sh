#!/bin/bash
./project7.exe myfile.txt > output1.txt
./project7.exe myfile.txt > output2.txt
diff output1.txt output2.txt
if [ $? -eq 0 ]
then
  echo "true"
else 
  echo "false"
fi