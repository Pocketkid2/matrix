//
//	Matrix.h - Matrix Header file
//		By Adam Taylor 2018
//

#ifndef MATRIX_H
#define MATRIX_H

//	TYPE DEFINITIONS	--------------------------------------------

typedef struct MatrixObj *Matrix;

//	CONSTRUCTOR AND DESTRUCTOR	------------------------------------

//	createMatrix(row, column)
//		Creates and returns a new matrix with the given size
//		row and column must be > 1
Matrix createMatrix(int r, int c);

//	freeMatrix(matrix)
//		Frees an existing matrix object that was previously
//		created in a call to createMatrix()
void freeMatrix(Matrix *m);

//	GETTER AND SETTER	--------------------------------------------

//	get(matrix, row, column)
//		Grabs the value at the specified index
//		row = 1...rows, column = 1...cols
double get(Matrix m, int r, int c);

//	get(matrix, row, column, value)
//		Updates the value at the specified index
//		row = 1...rows, column = 1...cols
void set(Matrix m, int r, int c, double v);

//	TEST FUNCTIONS	------------------------------------------------

//	print(matrix)
//		Prints out the matrix to the standard output as a formatted grid
void print(Matrix m);

//	MATH FUNCTIONS	------------------------------------------------

//	determinant(matrix)
//		Computes the determinant of a square matrix of any size > 1
double determinant(Matrix m);

#endif
