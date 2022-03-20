#include <iostream>
#include <cassert>
#include "matrix.h"

using std::cout, std::cin, std::endl;

void t_construction() {
	// test default construction
	{
		Matrix a;
		assert(a.getHeight() == 1);
		assert(a.getWidth() == 1);
		assert(a.at(0, 0) == 0);
	}

	// test construction with value other than default
	{
		Matrix a(1, 1, 4);
		assert(a.getHeight() == 1);
		assert(a.getWidth() == 1);
		assert(a.at(0, 0) == 4);
	}

	// test construction with an array
	{
		size_t m = 3;
		size_t n = 3;
		int* values = new int[9]{
			1,
			2,
			3,
			6,
			5,
			4,
			7,
			8,
			9
		};
		Matrix a(m, n, 9, values);
		assert(a.getHeight() == 3);
		assert(a.getWidth() == 3);
		unsigned int k = 0;
		for (unsigned int i = 0; i < a.getHeight(); i++) {
			for (unsigned int j = 0; j < a.getWidth(); j++, k++) {
				assert(a.at(i, j) == values[k]);
			}
		}

		delete[] values;

	}

	// test construction with an array smaller than the matrix
	{
		size_t m = 3;
		size_t n = 3;
		int* values = new int[6]{
			1,
			2,
			3,
			6,
			5,
			4
		};
		Matrix a(m, n, 6, values);
		assert(a.getHeight() == 3);
		assert(a.getWidth() == 3);
		unsigned int k = 0;
		for (unsigned int i = 0; i < a.getHeight(); i++) {
			for (unsigned int j = 0; j < a.getWidth(); j++, k++) {
				if (i == 2) {
					assert(a.at(i, j) == 0);
					continue;
				}

				assert(a.at(i, j) == values[k]);
			}
		}

		delete[] values;
	}

	// test construction with an array larger than the matrix

	// test construction with dimensions 0 x 0

	// test construction with
}

void t_multiplication() {

}

void t_addition() {
	// test addition and assignment of two matrices
	{/*
		Matrix a(3, 3, 2);
		m_assert_test(a, 2);
		Matrix b(3, 3, 3);
		m_assert_test(b, 3);
		a += b;
		m_assert_test(a, 5);
		assert(a != b);
		*/
	}
}

void t_inverse() {

}

void t_identity() {

}

void t_set_val() {

}

void t_fetch_r() {

}

void t_fetch_c() {

}

void t_at() {

}

int main() {
	t_construction();
	//t_multiplication();
	//t_addition();

	return 0;
}