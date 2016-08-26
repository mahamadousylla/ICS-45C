#include <iostream>
using namespace std;

const double KNOTS_IN_FEET = 6076.0;
const double MILES_IN_FEET = 5280.0;


double converter(int knots);
//converts given knots to miles per minute

int main() {
	int user_knots;
	double converted;
	cin >> user_knots;
	converted = converter(user_knots);
	cout << converted << endl;
}


double converter(int knots) {
	double knotsInMiles = KNOTS_IN_FEET/MILES_IN_FEET;
	double converted;
	
	double mph = knotsInMiles * knots;
	converted = mph * 0.0166667;

	return converted;
}