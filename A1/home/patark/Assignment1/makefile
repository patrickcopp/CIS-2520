all: carbon.o ackermann.o newton.o main

carbon: carbon.o header.h
	gcc -Wall -ansi -pedantic -c carbon.c -o carbon.o

ackermann: ackermann.o header.h
	gcc -Wall -ansi -pedantic -c ackermann.c -o ackermann.o

newton: newton.o header.h
	gcc -Wall -ansi -pedantic -c newton.c -o newton.o

main: main.c carbon.c ackermann.c newton.c header.h
	gcc -Wall -ansi -pedantic main.c carbon.c ackermann.c newton.c -o main

clean:
	rm -rf *.o
