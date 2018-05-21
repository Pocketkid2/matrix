//
//	Matrix.c - Matrix Implementation file
//		By Adam Taylor 2018
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "matrix.h"

typedef struct MatrixObj {
	double *data;	// An array of all the floating-point values
	uint8_t rows;	// The number of rows in the matrix
	uint8_t cols;	// The number of columns in the matrix
} MatrixObj;

Matrix createMatrix(int r, int c)
{
	if (r > 0 && c > 0) {
		Matrix m = malloc(sizeof(MatrixObj));
		if (m == NULL) {
			printf("Matrix Error: malloc() failed creating matrix object\n");
			exit(1);
		}
		m->rows = r;
		m->cols = c;
		m->data = malloc(sizeof(double) * r * c);
		if (m->data == NULL) {
			printf("Matrix Error: malloc() failed creating matrix data\n");
			exit(1);
		}
		return m;
	} else {
		printf("Matrix Error: Created matrix with rows or columns < 1\n");
		exit(1);
	}
}

void freeMatrix(Matrix *m)
{
	if (m != NULL && *m != NULL) {
		free((*m)->data);
		free(*m);
		*m = NULL;
	}
}

bool valid(Matrix m, int r, int c)
{
	// Checks if the given index is within the proper bounds for the matrix
	return !((r < 1) || (c < 1) || (r > m->rows) || (c > m->cols));
}

double get(Matrix m, int r, int c)
{
	if (m == NULL) {
		printf("Matrix Error: Calling get() on NULL matrix reference\n");
		exit(1);
	}
	if (!valid(m, r, c)) {
		printf("Matrix Error: Calling get() with invalid index values\n");
		exit(1);
	}
	// We expect indexes that start at 1
	// but the internal representation starts at 0
	r -= 1;
	c -= 1;
	// Compute the offset and then return the value
	int offset = (r * m->cols) + c;
	return *(m->data + offset);
}

void set(Matrix m, int r, int c, double v)
{
	if (m == NULL) {
		printf("Matrix Error: Calling get() on NULL matrix reference\n");
		exit(1);
	}
	if (!valid(m, r, c)) {
		printf("Matrix Error: Calling get() with invalid index values\n");
		exit(1);
	}
	// We expect indexes that start at 1
	// but the internal representation starts at 0
	r -= 1;
	c -= 1;
	// Compute the offset and assign the value
	int offset = (r * m->cols) + c;
	*(m->data + offset) = v;
}

void print(Matrix m)
{
	if (m == NULL) {
		printf("Matrix Error: Calling get() on NULL matrix reference\n");
		exit(1);
	}

	// Compute character width for headers
	int hlen = (9 * m->cols) + 1;

	// Loop through each row
	for (int i = 1; i <= m->rows; i++) {
		// First print the header
		for (int k = 0; k < hlen; k++) {
			printf("-");
		}
		printf("\n");

		// Then print the row
		for (int j = 1; j <= m->cols; j++) {
			printf("| %6.2lf ", get(m, i, j));
		}
		printf("|\n");
	}
	// Print the last header
	for (int k = 0; k < hlen; k++) {
		printf("-");
	}
	printf("\n");
}

bool equals(Matrix a, Matrix b)
{
	// Check the sizes
	if ((a->rows != b->rows) || (a->cols != b->cols)) {
		return false;
	}

	// Check each value
	for (int i = 1; i <= a->rows; i++) {
		for (int j = 1; j <= b->cols; j++) {
			if (get(a, i, j) != get(b, i, j)) {
				return false;
			}
		}
	} 

	// Otherwise must be equal
	return true;
}

Matrix matrixOfMinors(Matrix m, int r, int c)
{
	if (m == NULL) {
		printf("Matrix Error: Calling matrixOfMinors() on NULL matrix reference\n");
		exit(1);
	}
	if (!valid(m, r, c)) {
		printf("Matrix Error: Calling matrixOfMinors() with invalid index values\n");
		exit(1);
	}

	// Check that the size >= 2x2
	if (m->rows > 1 && m->cols > 1) {
		// The new matrix
		Matrix n = createMatrix(m->rows - 1, m->cols - 1);

		// The old matrix indexes
		int a = 1, b;

		// The new matrix indexes
		int i = 1, j;

		// Nested loop
		while (i <= n->rows) {

			// If the row matches
			if (r == a) {
				// Only increment the old index
				a++;
				continue;
			}

			j = 1;
			b = 1;
			while (j <= n->cols) {

				// If the column matches
				if (c == b) {
					// Only increment the old index
					b++;
					continue;
				}

				// Copy
				set(n, i, j, get(m, a, b));

				j++;
				b++;
			}

			i++;
			a++;
		}

		return n;
	} else {
		printf("Matrix Error: Calling matrixOfMinors() with matrix smaller than 2x2 not allowed\n");
		exit(1);
	}
}

double determinant(Matrix m)
{
	if (m == NULL) {
		printf("Matrix Error: Calling determinant() on NULL matrix reference\n");
		exit(1);
	}

	// Check that the matrix is square
	if (m->rows == m->cols) {

		// Move to single-variable
		int size = m->rows;

		// Recursive cases
		if (size == 1) {
			// If 1x1 simply return the value
			return get(m, 1, 1);
		} else {
			// Otherwise return the matrixOfMinors determinant sum
			double sum = 0.0;
			for (int i = 1; i <= size; i++) {
				// Grab top-row value
				double a = get(m, 1, i);
				// Grab determinant of minor matrix
				double b = determinant(matrixOfMinors(m, 1, i));
				// Grab negative modifier (-1 ^ row)
				double c = (i % 2) ? (1.0) : (-1.0);

				// Multiply the values and add in
				sum += (a * b * c);
			}
			// We have the final value so return it
			return sum;
		}

	} else {
		printf("Matrix Error: Calling determinant() on a non-square matrix\n");
		exit(1);
	}
}
