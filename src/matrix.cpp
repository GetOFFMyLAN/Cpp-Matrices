#include <iostream>
#include "matrix.h"

using std::cout, std::endl;
////// MATRIX CLASS /////

// constructors and desutrctors

/* 
* default constructor`
*/
Matrix::Matrix() : rows{1}, columns{1}, A{new int*[rows]} {
	for (size_t i = 0; i < rows; i++) {
		A[i] = new int[columns]{0};
	}
}


/* 
* construction of a matrix of size mxn with vall values the same
*/
Matrix::Matrix(size_t m, size_t n, int value) : rows{m}, columns{n}, A{new int*[rows]} {
	for (size_t i = 0; i < rows; i++) {
		A[i] = new int[columns]{0};
		for (size_t j = 0; j < columns; j++) {
			A[i][j] = value;
		}
	}
}

/*
* constructor for a matrix using an array of values
*/
Matrix::Matrix(size_t m, size_t n, int arr_size, const int* arr_vals) : rows{m}, columns{n}, A{new int*[rows]} {
	int k = 0;
	for (unsigned int i = 0; i < rows; i++) {
		A[i] = new int[columns]{0};
		for (unsigned int j = 0; j < columns && k < arr_size; j++, k++) {
			A[i][j] = arr_vals[k];
		}
	}
}

/*
* destructor for a matrix
*/
Matrix::~Matrix() {
	for (size_t i = 0; i < rows; i++) {
			delete[] A[i];
	}
	delete[] A;
}

/* 
* copy constructor
*/
Matrix::Matrix(const Matrix& mat) : rows{mat.rows}, columns{mat.columns}, A{new int*[rows]} {
	for (size_t i = 0; i < rows; i++) {
		A[i] = new int[columns];
		for (size_t j = 0; j < columns; j++) {
			this->A[i][j] = mat.A[i][j];
		}
	}
}

// member functions

/*
* Prints the matrix using a dynamically sized width based on the width of the largest value
* @return: void
*/
void Matrix::print() {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

/*
* sets the value of a specific index
* @param i : the index of the row of the value being changed
* @param j : the index of the column of the value being changed
* @param value : the value to be replaced at index [i][j]
* @update index [i][j] of the matrix
*/
void Matrix::setValue(size_t i, size_t j, int value) {
	// bounds checking
	if (i > rows - 1) {
		throw std::out_of_range("attempted to access invalid row index");
	} else if (j > columns - 1) {
		throw std::out_of_range("attempted to access invalid column index");
	}

	// otherwise set the value at (i, j) to value
	A[i][j] = value;
}

/*
* returns the value at an index
* @param i : row index of target value
* @param j : column index of target value
* @return the value at A[i][j] of the matrix
*/
int Matrix::at(size_t i, size_t j) {
	// bounds checking
	if (i > rows - 1) {
		throw std::out_of_range("attempted to access invalid row index");
	} else if (j > columns - 1) {
		throw std::out_of_range("attempted to access invalid column index");
	}

	// return value at (i, j)
	return A[i][j];
}

/*
* gets the entire row of a matrix as an array
* @param m : the index of the target row
* @return a pointer to the row array
*/
int* Matrix::fetchRow(size_t m) {
	if (m >= rows) {
		throw std::out_of_range("cant access a row index outside of the size of the matrix");
	}

	int* row = new int[columns];
	for (size_t k = 0; k < columns; k++) {
		row[k] = A[m][k];
	}
	return row;
}

/*
* gets the entire column of a matrix as an array
* @param n : the index of the target column
* @return a pointer to the column array
*/
int* Matrix::fetchColumn(size_t n) {
	if (n >= columns) {
		throw std::out_of_range("cant access a column index outside of the size of the matrix");
	}

	int* col = new int[rows];
	for (size_t k = 0; k < rows; k++) {
		col[k] = A[k][n];
	}
	return col;
}

////// MATRIX OPERATORS /////

/*
* copy assignment operator
*/
Matrix& Matrix::operator=(const Matrix& rhs) {
	if (this != &rhs) {
		rows = rhs.rows;
		columns = rhs.columns;
		for (size_t i = 0; i < rows; i++) {
			delete[] A[i];
		}
		delete[] A;

		this->A = new int*[rows];
		for (size_t i = 0; i < rows; i++) {
			this->A[i] = new int[columns];
			for (size_t j = 0; j < columns; j++) {
				this->A[i][j] = rhs.A[i][j];
			}
		}
	}
	return *this;
}

/*
* addition of two matrices
* matrices must have the same dimensions in order to be
* add each value respectively in each location (Aij)
* @param rhs : matrix added on the right hand side
* @return a reference to the left hand side matrix that values are being added to
*/
Matrix& Matrix::operator+(const Matrix& rhs) {
	/*if (this->A == nullptr || rhs.A == nullptr) {
		return nullptr;
	}*/

	if (this->rows != rhs.rows && this->columns	!= rhs.columns) {
		throw std::out_of_range("can't add two matrices of different sizes");
	}

	for (size_t	i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			this->A[i][j] = A[i][j] + rhs.A[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator+=(const Matrix& rhs) {
	/*if (this->A == nullptr || rhs.A == nullptr) {
		return nullptr;
	}*/

	if (this->rows != rhs.rows && this->columns	!= rhs.columns) {
		throw std::out_of_range("can't add two matrices of different sizes");
	}

	for (size_t	i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			this->A[i][j] = A[i][j] + rhs.A[i][j];
		}
	}

	return *this;
}

// subtraction

/*
* multiplication of two matrices
* the number of rows of the second matrix must be equal 
* to the number of columns of the first matrix
* @param a : the first matrix to be multiplied
* @param b : second matrix being multiplied to the first
* @return a reference to a new matrix that contains the multiplication of the two
*/
Matrix Matrix::operator*(const Matrix& rhs) {
	if (A == nullptr) {
		throw std::invalid_argument("cannot multiply nullptr by a Matrix");
	}

	if (columns != rhs.rows) {
		throw std::out_of_range("column size does not match row size in multiplication of matrices");
	}

	Matrix res;
	res.rows = rows;
	res.columns = rhs.columns;

	res.A = new int*[res.rows];
	for (size_t i = 0; i < rows; i++) {
		res.A[i] = new int[res.columns];
		for (size_t j = 0; j < rhs.columns; j++) {
			int sum = 0;
			for (size_t k = 0; k < columns; k++) {
				sum += (A[i][k] * rhs.A[k][j]);
			}
			res.A[i][j] = sum;
		}
	}
	return res;
}

/*
* same multiplication as above just with the assignment operator
*/
Matrix& Matrix::operator*=(const Matrix& rhs) {
	if (A == nullptr) {
		throw std::invalid_argument("cannot multiply nullptr by a Matrix");
	}

	if (columns != rhs.rows) {
		throw std::out_of_range("column size does not match row size in multiplication of matrices");
	}

	// copy current contents into temp Matrix before changing it
	Matrix tmp;
	tmp.rows = rows;
	tmp.columns = columns;
	tmp.A = new int*[tmp.rows];
	for (size_t i = 0; i < tmp.rows; i++) {
		tmp.A[i] = new int[tmp.columns];
		for (size_t j = 0; j < tmp.columns; j++) {
			tmp.A[i][j] = A[i][j];
		}
	}

	// delete whatever was in the old matrix
	for (size_t i = 0; i < rows; i++) {
		delete[] A[i];
	}
	delete[] A;

	if (this != &rhs) {
		// use tmp matrix to find result and change the data of the matrix being multiplied
		this->rows = tmp.rows; // probably dont need this since it redundant
		this->columns = rhs.columns;
		this->A = new int*[rows];
		for (size_t i = 0; i < rows; i++) {
			this->A[i] = new int[columns];
			for (size_t j = 0; j < rhs.columns; j++) {
				int sum = 0;
				for (size_t k = 0; k < tmp.columns; k++) {
					sum += (tmp.A[i][k] * rhs.A[k][j]);
				}
				this->A[i][j] = sum;
			}
		}
	} else {
		this->rows = tmp.rows;
		this->columns = tmp.columns;
		this->A = new int*[rows];
		for (size_t i = 0; i < rows; i++) {
			this->A[i] = new int[columns];
			for (size_t j = 0; j < columns; j++) {
				int sum = 0;
				for (size_t k = 0; k < columns; k++) {
					sum += (tmp.A[i][k] * tmp.A[k][j]);
				}
				this->A[i][j] = sum;
			}
		}
	}
	return *this;
}

/* 
* multiplication of a matrix by a scalar
* the size of the matrix should stay the same but each value in it should be multiplied by the vector
* dimensions dont change
* @return the result matrix of multiplying each value in the matrix by the scalar
* @update matrix values to result of individual multiplication
*/
Matrix& Matrix::operator*(int c) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			A[i][j] *= c;
		}
	}
	return *this;
}

/*
* same multiplication as above just with the assignment operator
*/
Matrix& Matrix::operator*=(int c) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			A[i][j] *= c;
		}
	}
	return *this;
}