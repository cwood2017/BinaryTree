# BinaryTree
Project 7 for cs 205

This project creates a binary search tree.  It reads in a file that is a list of integers and is passed as a parameter.  It creates the binary tree and then runs several methods on it. Run make to compile the project.  It creates a file called final.exe.  Execute with ./final.exe inputfile.txt

The project also includes a shell script (shell.sh) that can be used for regression testing.  The files error_arg_num.txt, error_unable.txt and BSTInput1-3 and BSTOutput1-3 are required for regression testing.  The script will output " --> The number of command line arguments is wrong." if no text file is passed in and it will output " --> Could not open file." if the filename is wrong or the file doesn't exist.  Running the shell script creates files output.txt, output1.txt, and output2.txt.  These will be erased by make clean.

Nick Crepeau
Cody Wood
Ethan Rocheleau
Nate Johnson
