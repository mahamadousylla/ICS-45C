#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
#include <string>
#include "Array.h"
using namespace std;

class RowIndexOutOfBoundsException {
	public:
		RowIndexOutOfBoundsException() {}
};

template<typename T>
class Matrix {
	private:
		int rows, cols;
	public:
		Array <Array<T>*> m;
		Matrix(int newRows, int newCols)
			: rows(newRows), cols(newCols), m(rows)
			{
				for (int i = 0; i < rows; i++) {
					m[i] = new Array <T>(cols);
				}
			}

		int numRows() {
			return rows;
		}

		int numCols() {
			return cols;
		}

		bool inbounds(int i) {
			return 0 <= i && i < rows;
		}

		Array <T> & operator [] (int row) {
			if (!inbounds(row)) {
				throw RowIndexOutOfBoundsException();
			}
			return *m[row];
		}

		void print(ostream &out) {
			for (int i = 0; i < rows; i++) {
				out << m[i] << endl;
			}
		}

		friend ostream & operator << (ostream &out, Matrix &m) {
			m.print(out);
			return out;
		}
};

#endif /* MATRIX_H_ */