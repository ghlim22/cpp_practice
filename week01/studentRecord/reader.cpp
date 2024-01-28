#include "studentRecord.h"
#include <fstream>
#include <ios>
#include <iostream>
int main(void)
{
	struct StudentRecord s;
	std::fstream fin("studentRecord.dat", std::ios_base::in | std::ios_base::binary);

	if (!fin.is_open()) {
		return 0;
	}

	fin.read((char *)&s, sizeof(s));
	if (fin.fail()) {
		std::cout << "fail on read()\n";
		return 0;
	}

	std::cout << "grade: " << s.grade << std::endl;
	std::cout << "name: " << s.name << std::endl;

	return 0;
}