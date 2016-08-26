#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

class ColIndexOutOfBoundsException {
public:
	ColIndexOutOfBoundsException() {}
};

template<typename T>
class Array
{
	private:
		int len;
		T *buf;

	public:
		Array(int newLen)
			: len(newLen), buf(new T[newLen]) {}

		Array(const Array &l)
			: len(l.len), buf(new T[l.len])
			{
				for (int i = 0; i < l.len; i++) {
					buf[i] = l.buf[i];
				}
			}

		int length() {
			return len;
		}

		bool inbounds(int i) {
			return 0 <= i && i < len;
		}

		T & operator [] (int i) {
			if (!inbounds(i)) {
				throw ColIndexOutOfBoundsException();
			}
			assert(0 <= i && i < len);
			return buf[i];
		}

		void print(ostream &out) {
			for (int i = 0; i < len; i++) {
				out << setw(8) << setprecision(2) << fixed << right << buf[i];
			}
		}

		friend ostream & operator << (ostream &out, Array &a) {
			a.print(out);
			return out;
		}

		friend ostream & operator << (ostream &out, Array *ap) {
			ap->print(out);
			return out;
		}
};

#endif /* ARRAY_H_ */