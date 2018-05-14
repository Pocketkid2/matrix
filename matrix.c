//
//	Matrix.c - Matrix Implementation file
//		By Adam Taylor 2018
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

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
			printf("| %3.2lf ", get(m, i, j));
		}
		printf("|\n");
	}
	// Print the last header
	for (int k = 0; k < hlen; k++) {
		printf("-");
	}
	printf("\n");
}

double determinant(Matrix m)
{
	printf("Placeholder for determinant()\n");
	return 0.0;
}
