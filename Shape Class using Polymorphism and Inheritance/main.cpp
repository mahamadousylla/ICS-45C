#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Picture.h"
#include <iostream>
using namespace std;

void testShapeAreas() {
	Triangle FirstTriangle(2.5, 2.5, "FirstTriangle");
	Triangle SecondTriangle(1.5, 2, "SecondTriangle");
	Circle FirstCircle(5, 5, "FirstCircle");
	Circle SecondCircle(10, 10, "SecondCircle");
	Square FirstSquare(2.5, 2.5, "FirstSquare");
	Square SecondSquare(5, 5, "SecondSquare");
	Rectangle FirstRectangle(2, 2, "FirstRectangle", 8);
	Rectangle SecondRectangle(4, 4, "SecondRectangle", 4);
	double T1 = FirstTriangle.area();
	cout << "FirstTriangle: " << T1 << endl;
	double T2 = SecondTriangle.area();
	cout << "SecondTriangle: " << T2 << endl;
	double C1 = FirstCircle.area();
	cout << "FirstCircle: " << C1 << endl;
	double C2 = SecondCircle.area();
	cout << "SecondCircle: " << C2 << endl;
	double S1 = FirstSquare.area();
	cout << "FirstSquare: " << S1 << endl;
	double S2 = SecondSquare.area();
	cout << "SecondSquare: " << S2 << endl;
	double R1 = FirstRectangle.area();
	cout << "FirstRectangle: " << R1 << endl;
	double R2 = SecondRectangle.area();
	cout << "SecondRectangle: " << R2 << endl;
	cout << "Total area: " << T1 + T2 + C1 + C2 + S1 + S2 + R1 + R2 << endl;
}

void testShapeDraw() {
	Triangle FirstTriangle(2.5, 2.5, "FirstTriangle");
	Triangle SecondTriangle(1.5, 2, "SecondTriangle");
	Circle FirstCircle(5, 5, "FirstCircle");
	Circle SecondCircle(10, 10, "SecondCircle");
	Square FirstSquare(2.5, 2.5, "FirstSquare");
	Square SecondSquare(5, 5, "SecondSquare");
	Rectangle FirstRectangle(2, 2, "FirstRectangle", 8);
	Rectangle SecondRectangle(4, 4, "SecondRectangle", 4);
	FirstSquare.draw();
	SecondSquare.draw();
	FirstRectangle.draw();
	SecondRectangle.draw();
	FirstTriangle.draw();
	SecondTriangle.draw();
	FirstCircle.draw();
	SecondCircle.draw();
}


int main () {
//	testShapeAreas();
//	testShapeDraw();

	Picture picture;
	Triangle FirstTriangle(2.5, 2.5, "FirstTriangle");
	Triangle SecondTriangle(1.5, 2, "SecondTriangle");
	Circle FirstCircle(5, 5, "FirstCircle");
	Circle SecondCircle(10, 10, "SecondCircle");
	Square FirstSquare(2.5, 2.5, "FirstSquare");
	Square SecondSquare(5, 5, "SecondSquare");
	Rectangle FirstRectangle(2, 2, "FirstRectangle", 8);
	Rectangle SecondRectangle(4, 4, "SecondRectangle", 4);

	picture.add(&FirstTriangle);
	picture.add(&SecondTriangle);
	picture.add(&FirstCircle);
	picture.add(&SecondCircle);
	picture.add(&FirstSquare);
	picture.add(&SecondSquare);
	picture.add(&FirstRectangle);
	picture.add(&SecondRectangle);

	cout << "Draw All:" << endl;
	picture.drawAll();
	cout << endl;
	cout << "Total Area: " << picture.totalArea() << endl;
}
