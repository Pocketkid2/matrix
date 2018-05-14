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
	double *data;
	uint8_t rows;
	uint8_t cols;
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
	return (r < 1) || (c < 1) || (r > m->rows) || (c > m->cols);
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
	r -= 1;
	c -= 1;
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
	r -= 1;
	c -= 1;
	int offset = (r * m->cols) + c;
	*(m->data + offset) = v;
}

void print(Matrix m)
{
	if (m == NULL) {
		printf("Matrix Error: Calling get() on NULL matrix reference\n");
		exit(1);
	}
	printf("Placeholder for print()\n");
}

double determinant(Matrix m)
{
	printf("Placeholder for determinant()\n");
	return 0.0;
}
