final.exe: main.o binary_tree.o
	gcc main.o binary_tree.o -o final.exe

main.o: main.c binary_tree.h
	gcc -Wall -c main.c
	
binary_tree.o: binary_tree.c binary_tree.h
	gcc -Wall -c binary_tree.c binary_tree.h

clean:
	rm *.o final.exe
	ls
