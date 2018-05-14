//
//	MatrixTest.c - Matrix Unit Test
//		By Adam Taylor 2018
//

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main()
{
	Matrix a = createMatrix(3, 3);
	Matrix b = createMatrix(2, 2);

	set(a, 1, 1, 1);
	set(a, 1, 2, 2);
	set(a, 1, 3, 3);
	set(a, 2, 1, 4);
	set(a, 2, 2, 5);
	set(a, 2, 3, 6);
	set(a, 3, 1, 7);
	set(a, 3, 2, 8);
	set(a, 3, 3, 9);

	set(b, 1, 1, -1);
	set(b, 1, 2, -2);
	set(b, 2, 1, 0.0);
	set(b, 2, 2, 100);

	print(a);
	print(b);
}
