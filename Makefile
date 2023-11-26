all: main.o functions.o
	gcc main.o functions.o -o 2lab
functions.o: functions.c
	gcc -c functions.c
main.o: main.c
	gcc -c main.c
