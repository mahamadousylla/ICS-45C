#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <string>

using namespace std;

class Triangle : public Shape
{
	public:
		Triangle(double centerX, double centerY, string name)
			: Shape(centerX, centerY, name), x(centerX), y(centerY), name(name) {}

		virtual void draw() {
	        int i;
	        int k;
	        for (i = 0; i <= (x*2); i++) {
	          cout << endl;
	          for (k = 0; k <= i; k++) {
	                 cout << "*";
	          }
	        } cout << endl;
		}

		virtual double area() {
			return ((x * 2) * (y * 2))/2;
		}

		virtual ~Triangle() {}

	protected:
		double x;
		double y;
		string name;
};

#endif /* TRIANGLE_H_ */
