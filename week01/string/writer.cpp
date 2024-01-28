#include <fstream>
#include <ios>
#include <iostream>
#include <string>
int main(void)
{
	std::string s;
	std::fstream fout("data.txt", std::ios_base::out | std::ios_base::trunc);

	if (!fout.is_open()) {
		return 0;
	}

	while (true) {
		std::getline(std::cin, s);
		if (!std::cin.fail()) {
			fout << s << std::endl;
			continue;
		}
		if (std::cin.eof()) {
			break;
		}
	}

	fout.close();

	return 0;
}