#include "PigLatin.h"

#include <iostream>
#include <exception>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: piglatin FILE" << std::endl;
		std::cout << "Pig Latin is a language obfuscation game/tool." << std::endl;
		std::cout << std::endl << "Transform and obfuscate a plain text file" << std::endl;
		std::cout << "Takes one argument FILE and outputs FILE.pig regardless of any existing file extention." << std::endl;
		return 1;
	}

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
