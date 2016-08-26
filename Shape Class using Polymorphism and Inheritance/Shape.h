#ifndef SHAPE_H_
#define SHAPE_H_
#include <iostream>
#include <string>
using namespace std;

class Shape
{
	public:
		Shape(double centerX, double centerY, string name)
			: x(centerX), y(centerY), name(name) {}

		virtual void draw() = 0;

		virtual double area() = 0;

		virtual ~Shape() {}

	protected:
		double x;
		double y;
		string name;
};

#endif /* SHAPE_H_ */
