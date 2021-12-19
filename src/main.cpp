#include "PigLatin.h"

#include <iostream>
#include <exception>

int main(int argc, char **argv)
{

	try
	{
		PigLatin pl(argv[1]);

	}
	catch (std::string& e)
	{
		std::cout << e << std::endl;
		return 2;
	}
	catch (std::exception& e)
	{
		std::cout << "Faild to obfuscate file: " << e.what() << std::endl;
		return 3;
	}

	return 0;
}
