#include <ios>
#include <iostream>

int main(void)
{
	/* Manipulators */
	int num = 10;

	std::cout << std::showbase << std::hex << num << '\n';
	
	/* show positive */
	std::cout << std::showpos << num << '\n';
	std::cout << std::noshowpos << num << '\n';

	/* base */
	std::cout << std::dec << num << '\n';
	std::cout << std::hex << num << '\n';
	std::cout << std::oct << num << '\n';

	/* case */
	std::cout << std::uppercase << std::hex << num << '\n';
	std::cout << std::nouppercase << std::hex << num << '\n';

	/* show base */
	std::cout << std::showbase << std::hex << num << '\n';
	std::cout << std::noshowbase << std::hex << num << '\n';




	return 0;
}