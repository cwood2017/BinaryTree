#!/bin/bash
# This script will create three files: output.txt, output1.txt, output2.txt
# It uses 8 input files: BSTInput1.txt, BSTInput2.txt, BSTInput3.txt, 
# BSTOutput1.txt, BSTOutput2.txt, BSTOutput3.txt, error_unable.txt,
# and error_arg_num.txt.
echo "Testing identical outputs:"
./final.exe myfile.txt > output1.txt
./final.exe myfile.txt > output2.txt
diff output1.txt output2.txt > /dev/null
if [ $? -eq 0 ]
then
  echo " --> Correct."
  echo
else
  echo " --> Incorrect."
  echo
fi
#demonstrate wrong number of arguments
echo "Testing wrong number of args:"
./final.exe > output1.txt
diff output1.txt error_arg_num.txt > /dev/null
if [ $? -eq 0 ]
then
  echo " --> The number of command line arguments is wrong."
  echo
fi
diff output1.txt error_unable.txt > /dev/null
if [ $? -eq 0 ]
then
  echo " --> Could not open file."
  echo
fi
#demonstrates unable to open file
echo "Testing unable to open file:"
./final.exe notarealfile.txt> output2.txt
diff output2.txt error_arg_num.txt > /dev/null
if [ $? -eq 0 ]
then
  echo " --> The number of command line arguments is wrong."
  echo
fi
diff output2.txt error_unable.txt > /dev/null
if [ $? -eq 0 ]
then
  echo " --> Could not open file."
  echo
fi
#testing first sample input
echo "Testing BSTInput1.txt:"
./final.exe BSTInput1.txt > output.txt
diff output.txt BSTOutput1.txt > /dev/null
if [ $? -eq 0 ]
then
  echo " --> Correct."
  echo
else
   echo " --> Incorrect."
   echo
    diff output.txt error_arg_num.txt > /dev/null
    if [ $? -eq 0 ]
        then
        echo " --> The number of command line arguments is wrong."
        echo
    fi
    diff output.txt error_unable.txt > /dev/null
    if [ $? -eq 0 ]
        then
        echo " --> Could not open file."
        echo
    fi
fi
#testing second sample input
echo "Testing BSTInput2.txt:"
./final.exe BSTInput2.txt > output.txt
diff output.txt BSTOutput2.txt > /dev/null
if [ $? -eq 0 ]
  then
  echo " --> Correct."
  echo
else
   echo " --> Incorrect."
   echo
    diff output.txt error_arg_num.txt > /dev/null
    if [ $? -eq 0 ]
        then
        echo " --> The number of command line arguments is wrong."
        echo
    fi
    diff output.txt error_unable.txt > /dev/null
    if [ $? -eq 0 ]
        then
        echo " --> Could not open file."
        echo
    fi
fi
#testing third sample input
echo "Testing BSTInput3.txt:"
./final.exe BSTInput3.txt > output.txt
diff output.txt BSTOutput3.txt > /dev/null
if [ $? -eq 0 ]
  then
  echo " --> Correct."
  echo
else
   echo " --> Incorrect."
   echo
    diff output.txt error_arg_num.txt > /dev/null
    if [ $? -eq 0 ]
        then
        echo " --> The number of command line arguments is wrong."
        echo
    fi
    diff output.txt error_unable.txt > /dev/null
    if [ $? -eq 0 ]
        then
        echo " --> Could not open file."
        echo
    fi
fi