#include <fstream>
#include <ios>
#include <iostream>
#include "studentRecord.h"

int main(void)
{
	struct StudentRecord s = {20, "Alexis Sanchez"};
	std::fstream fout("studentRecord.dat", std::ios_base::out | std::ios_base::binary);

	if (!fout.is_open()) {
		std::cout << "open error\n";
		return 0;
	}
	fout.write((char *)&s, sizeof(s));
	fout.close();
	return 0;
}