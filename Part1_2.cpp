#include <iostream>
#include <sstream>
#include <string>

int main()
{
	std::string line;
	std::getline(std::cin, line);
	std::istringstream stream{ line };
	std::string s;
	stream >> s;
	std::cout << "[" << s;
	while (stream >> s)
	{
		std::cout << ", " << s;
	}
	std::cout << "]";
	std::cout << std::endl;
	system("pause");
	return 0;
}