$(CC) = gcc

code1:code1.o add.o
	$(CC) code1.o add.o -o output

code1.o:code1.c add.h
	$(CC) -c code1.c

add.o:add.c add.h
	$(CC) -c add.c

clean: 
	rm -rf *.o output
