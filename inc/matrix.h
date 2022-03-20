#ifndef MATRIX_H
#define MATRIX_H

// matrix class definition
class Matrix {
	private:
		size_t rows;
		size_t columns;
		int** A = nullptr; // dynamically allocate memory for 2d array

	public:
		Matrix(); // default constructor
		Matrix(size_t m, size_t n, int value); // constructor for n x m matrix with all the same values
		Matrix(size_t m, size_t n, int arr_size, const int* arr_vals); // constructor for n x m matrix using an array of values		
		~Matrix(); // destructor
		Matrix(const Matrix& mat); // copy constructor

		// void member functions
		void print(); 		 		 // pretty prints the matrix
		void setValue(size_t i, size_t j, int value); // sets the value of matrix location (i, j)
		void resize_w(size_t n); // resize the matrix to a new width
		void resize_h(size_t m); // resize the matrix to a new height

		// non void member functions
		int at(size_t i, size_t j);	 	 // retuns the value at location (i, j)
		size_t getWidth() const { return columns; } // returns the number of rows
		size_t getHeight() const { return rows; } // returns the number of columns
		int* fetchRow(size_t m);		// returns an entire row at index (m, k)
		int* fetchColumn(size_t n);	// returns an entire column at index (k, n)
		Matrix identity();

		// operators
		Matrix& operator=(const Matrix& rhs); // copy assignment operator
		Matrix operator*(const Matrix& rhs); // multiplication by another matrix
		Matrix& operator*=(const Matrix& rhs); // multiplication by another matrix in one assignment (i.e. A *= B) 
		Matrix& operator*(int c); // multiplication by scalar (scalar on rhs)
		Matrix& operator*=(int c); // multiplication by scalar in one assignment (i.e M *= 2)
		Matrix& operator+(const Matrix& rhs); // addition of two matrices
		Matrix& operator+=(const Matrix& rhs); // addition and assignment of two matrices
		Matrix& operator-(const Matrix& rhs); // subtraction of two matrices
		Matrix& operator-=(const Matrix& rhs); // subtraction and assignment of two matrices

};

/*
TODOs: 
- add identity method to return the identity matrix of the same size
- add eigenvalue method
- add determinant method
*/


#endif
