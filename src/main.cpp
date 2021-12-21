#include "PigLatin.h"

#include <iostream>
#include <exception>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: piglatin INFILE OUTFILE" << std::endl;
		std::cout << "Pig Latin is a language obfuscation game/tool." << std::endl;
		std::cout << std::endl << "Transform and obfuscate a plain text file" << std::endl;
		std::cout << "Takes two arguments INFILE and OUTFILE" << std::endl;
		return 1;
	}

	try
	{
		PigLatin *pl = new PigLatin(lt::Danish);

		pl->encodeFile(argv[1], argv[2]);

		delete pl;

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
