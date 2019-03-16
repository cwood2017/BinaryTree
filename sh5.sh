#!/bin/bash
#demonstrates output matching
./final.exe myfile.txt > output1.txt
./final.exe myfile.txt > output2.txt
diff output1.txt output2.txt
if [ $? -eq 0 ]
then
  echo "Correct."
fi
#demonstrate wrong number of arguments
./final.exe > output1.txt
diff output1.txt error_arg_num.txt > /dev/null
if [ $? -eq 0 ]
then
  echo "The number of command line arguments is wrong."
fi
diff output1.txt error_unable.txt > /dev/null
if [ $? -eq 0 ]
then
  echo "Could not open file."
fi
#demonstrates unable to open file
./final.exe notarealfile.txt> output1.txt
diff output1.txt error_arg_num.txt > /dev/null
if [ $? -eq 0 ]
then
  echo "The number of command line arguments is wrong."
fi
diff output1.txt error_unable.txt > /dev/null
if [ $? -eq 0 ]
then
  echo "Could not open file."
fi