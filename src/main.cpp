#include "PigLatin.h"

#include <iostream>
#include <exception>
#include <algorithm>
#include <map>

int main(int argc, char **argv)
{
	if (argc != 3 && argc != 4)
	{
		std::cout << "Usage: piglatin INFILE OUTFILE [language]" << std::endl;
		std::cout << "Pig Latin is a language obfuscation game/tool." << std::endl;
		std::cout << std::endl << "Transform and obfuscate a plain text file." << std::endl;
		std::cout << std::endl << "piglatin takes two arguments INFILE and OUTFILE" << std::endl;
		std::cout << "An optional third argument specifying a language can also be set." << std::endl;
		std::cout << "language options:" << std::endl;
		std::cout << "\tDanish (default)" << std::endl;
		std::cout << "\tNorwegian" << std::endl;
		std::cout << "\tSweedish" << std::endl;
		std::cout << "\tEnglish" << std::endl;
		std::cout << "\tDeutsch" << std::endl;
		return 1;
	}

	lt::lang_t language = lt::Danish;
	if (argc == 4)
	{
		std::string usrLang = argv[3];
		std::transform(usrLang.begin(), usrLang.end(), usrLang.begin(), [](const char& ch){return std::tolower(ch);});

		std::map<const std::string, const lt::lang_t> langLookupMap = {
				std::pair<const std::string, const lt::lang_t>("danish", lt::Danish),
				std::pair<const std::string, const lt::lang_t>("norwegian", lt::Norwegian),
				std::pair<const std::string, const lt::lang_t>("sweedish", lt::Sweedish),
				std::pair<const std::string, const lt::lang_t>("english", lt::English),
				std::pair<const std::string, const lt::lang_t>("deutsch", lt::Deutsch)
		};

		if (langLookupMap.find(usrLang) == langLookupMap.end())
			std::cout << "Unknown language: " << usrLang << std::endl << "\tProceeding with default language(Danish)" << std::endl;
		language = langLookupMap[usrLang];
	}

	try
	{
		PigLatin *pl = new PigLatin(language);

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
