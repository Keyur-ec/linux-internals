.SILENT: 

FILENAME = code1 
#SRC = $(shell find -name '*.c')
SRC = ./src/*.c
INC = ./includes

default: compile run clean

compile: 
	#gcc -o $(FILENAME) $(SRC)
	gcc $(SRC) -I $(INC) -o $(FILENAME)

run: 
	./$(FILENAME)

clean:
	rm $(FILENAME)
