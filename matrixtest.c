//
//	MatrixTest.c - Matrix Unit Test
//		By Adam Taylor 2018
//

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main()
{

printf("TESTING 3x3 AND 2x2 MATRIX\n");

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

printf("TESTING MATRIX OF MINORS\n");

	// Test the matrix of minors
	Matrix n = matrixOfMinors(a, 1, 1);

	print(n);

	n = matrixOfMinors(a, 2, 2);

	print(n);

	n = matrixOfMinors(a, 3, 3);

	print(n);

	printf("TESTING MATRIX DETERMINANT\n");

	printf("%lf\n", determinant(a));

	printf("%lf\n", determinant(b));

	printf("%lf\n", determinant(n));

	printf("TESTING MATRIX EQUALS\n");

	Matrix c = createMatrix(3, 3);

	set(c, 1, 1, 1);
	set(c, 1, 2, 2);
	set(c, 1, 3, 3);
	set(c, 2, 1, 4);
	set(c, 2, 2, 5);
	set(c, 2, 3, 6);
	set(c, 3, 1, 7);
	set(c, 3, 2, 8);
	set(c, 3, 3, 9);

	printf("A = C: %s\n", equals(a, c) ? "true" : "false");
}
