all: main

main: main.o game.o utils.o
	gcc main.o game.o utils.o -o game.out -I .

game.o: game.c
	gcc -c game.c -I .

utils.o: utils.c 
	gcc -c utils.c -I .

main.o: main.c
	gcc -c main.c -I .

clean:
	rm *.o*

run: main
	./game.out
