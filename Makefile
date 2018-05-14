test: matrixtest.c matrix.o
	gcc -std=c99 -Wall -o matrixtest matrixtest.c matrix.o

matrix.o: matrix.c matrix.h
	gcc -std=c99 -Wall -c matrix.c

clean:
	rm *.o matrixtest
