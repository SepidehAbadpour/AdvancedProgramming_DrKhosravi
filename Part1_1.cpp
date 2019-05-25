#include <iostream>
using namespace std;

int main()
{
	float InchDistance = 0;
	float CentimeterDistance = 0;
	cout << "Enter the distance in inches:";
	cin >> InchDistance;
	CentimeterDistance = 2.54*InchDistance;
	cout << "The distance in centimeters will be: " << CentimeterDistance << endl;
	return 0;
}