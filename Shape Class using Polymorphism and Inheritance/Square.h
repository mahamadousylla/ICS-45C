#ifndef SQUARE_H_
#define SQUARE_H_
#include <iostream>
#include <string>
using namespace std;

class Square : public Shape
{
	public:
		Square(double centerX, double centerY, string name)
			: Shape(centerX, centerY, name), x(centerX), y(centerY), name(name)
		{
			assert(x == y);
		}

		virtual void draw() {
			for (int i=0; i < (x*2)+1; i++) {
				cout << '*' << ' ';
			}
			for (int j=0; j < (y * 2)-1; j++) {
				cout << endl << '*' << ' ';
				for (int i=0; i < (x*2)-1; i++) {
					cout << ' ' << ' ';
				}
				cout << '*';
			}
			cout << endl;
			for (int i=0; i < (x*2)+1; i++) {
				cout << '*' << ' ';
			}
			cout << endl << endl;
		}

		virtual double area() {
			return (x * 2) * (y * 2);
		}

		virtual ~Square() {}

	protected:
		double x;
		double y;
		string name;
};

#endif /* SQUARE_H_ */
