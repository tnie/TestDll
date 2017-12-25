#include <iostream>
#include "add.h"

int main(int argc, char* argv[])
{
	std::cout << add("the result of", "£¨add(1, 2)£©:") << add(1, 2) << std::endl;
	return 0;
}
