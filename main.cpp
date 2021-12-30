#include <iostream>
#include <cassert>
#include "matrix.h"

using std::cout, std::cin, std::endl;

void m_assert_test(const Matrix m, int val) {
	for (size_t i = 0; i < m.getHeight(); i++) {
		for (size_t j = 0; j < m.getWidth(); j++) {
			assert(m.at(i, j) == val);
		}
	}
}

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

	}

	// test construction with an array
	{

	}
}

void t_multiplication() {

}

void t_addition() {
	// test addition and assignment of two matrices
	{
		Matrix a(3, 3, 2);
		m_assert_test(a, 2);
		Matrix b(3, 3, 3);
		m_assert_test(b, 3);
		a += b;
		m_assert_test(a, 5);
		assert(a != b);
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
	//t_construction();
	//t_multiplication();
	t_addition();

	return 0;
}