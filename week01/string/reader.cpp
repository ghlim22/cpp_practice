#include <fstream>
#include <ios>
#include <iostream>
#include <string>
int main(void)
{
	std::fstream fin("data.txt", std::ios_base::in);
	std::string s;

	if (!fin.is_open()) {
		return 0;
	}

	while (true) {
		std::getline(fin, s);
		if (!fin.fail()) {
			std::cout << s << std::endl;
		}
		if (fin.eof()) {
			break;
		}
	}

	fin.close();

	return 0;
}