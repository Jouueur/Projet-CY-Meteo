FLAGS=-lm -W -Wall -Wextra -O3 -ggdb
BIN_DIR=./bin/

main-project : mainc.o avl.o abr.o 
	gcc $(BIN_DIR)*.o -o main-project

mainc.o : mainc.c
	gcc -c mainc.c -o $(BIN_DIR)mainc.o

abr.o : abr.c
	gcc -c abr.c -o $(BIN_DIR)abr.o

avl.o : avl.c
	gcc -c avl.c -o $(BIN_DIR)avl.o

clean :
	rm ./bin/*.o
	rm main-project
