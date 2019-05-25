#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<char> V1(100, 'A');
	cout << V1[99] << endl;
	vector<char> V2{'A','B','C','D','E','F','G','H','I','G','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	cout << V2[25] << endl;
	cin.ignore();
	cin.get();
	return 0;
}