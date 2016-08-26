#include "Matrix.h"
#include "Array.h"
#include <iostream>
using namespace std;

template <typename T>
void fillMatrix(Matrix <T> & m) {
	int i, j;
	for (i = 0; i < m.numRows(); i++) {
		m[i][0] = T();
	}
	for (j = 0; j < m.numCols(); j++) {
		m[0][j] = T();
	}
	for (i = 1; i < m.numRows(); i++) {
		for (j = 1; j < m.numCols(); j++) {
			m[i][j] = T(i * j);
		}
	}
}

void test_int_matrix() {
	Matrix <int> m(10,5);
	fillMatrix(m);
	cout << m;
}

void test_double_matrix() {
	Matrix <double> M(8,10);
	fillMatrix(M);
	cout << M;
}

void test_exception() {
	int rows, cols, rindex, cindex;
	try {
		cout << "Enter number of rows: ";
		cin >> rows;
		cout << "Enter number of columns: ";
		cin >> cols;
		Matrix <int> m(rows, cols);
		fillMatrix(m);
		cout << "Enter a row index: ";
		cin >> rindex;
		cout << "Enter a column index: ";
		cin >> cindex;
		cout << "Row Values: ";
		cout << m[rindex] << endl;
		cout << "Column Values: ";
		cout << m[cindex] << endl;
	}
	catch (...) {
		cout << "Index out of bounds!!" << endl;
	}
}

int main() {
	test_int_matrix();
	test_double_matrix();
	test_exception();
	return 0;
}