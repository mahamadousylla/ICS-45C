#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
#include <string>
using namespace std;

class Rectangle : public Square
{
	public:
		Rectangle(double centerX, double centerY, string name, double width)
			: Square(centerX, centerY, name), x(centerX), y(centerY), name(name), width(width) {}

		virtual void draw() {
			for (int i=0; i < (width)+1; i++) {
				cout << '*' << ' ';
			}
			for (int j=0; j < (y * 2)-1; j++) {
				cout << endl << '*' << ' ';
				for (int i=0; i < (width)-1; i++) {
					cout << ' ' << ' ';
				}
				cout << '*';
			}
			cout << endl;
			for (int i=0; i < (width)+1; i++) {
				cout << '*' << ' ';
			}
			cout << endl << endl;
		}

		virtual double area() {
			return width * (y * 2);
		}

		virtual ~Rectangle() {}

	protected:
		double x;
		double y;
		string name;
		double width;
};

#endif /* RECTANGLE_H_ */
