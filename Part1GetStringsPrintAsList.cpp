#include <iostream>
#include <string>
using namespace std;

int main()
{
	string current;
	int counter = 1;
	while (cin >> current)
	{
		if (counter == 1)
			cout << '[' << current << ", ";
		else
			cout << current << ", ";
		counter = counter + 1;
	}
	//cout << ']' << endl;
	return 0;
}