.SILENT:

CC = gcc
FILENAME = code
DBUG = gdb
MEMCHK = valgrind

default: compile run

compile: 
	$(CC) -o $(FILENAME) $(FILENAME).c

run: 
	./$(FILENAME)

debug:
	$(CC) -o $(FILENAME) $(FILENAME).c -g
	$(DBUG) ./$(FILENAME)

debug_w_core:
	#$(CC) -o $(FILENAME) $(FILENAME).c -g
	$(DBUG) ./$(FILENAME) ./core.*

mem_check: 
	$(MEMCHK) --leak-check=full ./$(FILENAME)

clean:
	rm -rf ./$(FILENAME)
	rm -rf ./core.*
