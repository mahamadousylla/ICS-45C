#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>
using namespace std;

class Circle : public Shape
{
	public:
		Circle(double centerX, double centerY, string name)
			: Shape(centerX, centerY, name), x(centerX), y(centerY), name(name)
		{
			assert(x == y);
		}

		virtual void draw() {
			for (int i = 0; i <= (x*2); i++) {
			    for (int j = 0; j <= (x*2); j++) {
			    	float distance = sqrt((i - x)*(i - x) + (j - x)*(j - x));
			    	if (distance > x-0.5 && distance < x+0.5) {
			    		cout << "*";
			    	} else {
			    		cout << " ";
			    	}
			    }
			    cout << endl;
			}
		}

		virtual double area() {
			return x * x * pi;
		}

		virtual ~Circle() {}

	private:
		const static double pi = 3.1415926;

	protected:
		double x;
		double y;
		string name;
};

#endif /* CIRCLE_H_ */
