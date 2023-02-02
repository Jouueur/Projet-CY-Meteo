FLAGS=-lm -W -Wall -Wextra -O3 -ggdb
BIN_DIR=./bin/

main-project : mainc.o avl.o abr.o 
    gcc $(BIN_DIR)*.o -o main-project $(FLAGS)

mainc.o : mainc.c
    gcc -c mainc.c -o $(BIN_DIR)mainc.o $(FLAGS)

abr.o : abr.c
    gcc -c abr.c -o $(BIN_DIR)abr.o $(FLAGS)

avl.o : avl.c
    gcc -c avl.c -o $(BIN_DIR)avl.o $(FLAGS)

clean :
    rm ./bin/*.o
    rm main-project
