ㅁㄴㅇㅁㅇㅁㅁ#include <iomanip>
#include <iostream>

int main(void)
{
	char name[4];

	std::cin >> std::setw(4) >> name;
	std::cout << name << std::endl;

	return 0;
}
