/*
 * PigLatin.cpp
 *
 *  Created on: Dec 17, 2021
 *      Author: magnus
 */

#include "PigLatin.h"

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <streambuf>
#include <locale>
#include <string_view>
#include <stdio.h>

PigLatin::PigLatin(const lt::lang_t& lang) :
	language(lang)
{
}

PigLatin::~PigLatin()
{
	if (ifs.is_open())
		ifs.close();
	if (ofs.is_open())
		ofs.close();
}

std::string& PigLatin::obfuscateWord(std::string& word) const
{
	auto index = static_cast<unsigned char>(word.front());
	if (booleanVCMap[language][index])
	{
		// Handle vowels.
		word += "yay";
	}
	else
	{
		// Handle consonants.
		// Skip single letter words.
		if (word.length() > 1)
		{
			auto findVowel = [this](const char& letter) {
				return booleanVCMap[language][letter];
			};
			auto firstVowelIt = std::find_if(word.begin() + 1, word.end(), findVowel);
			std::rotate(word.begin(), firstVowelIt, word.end());
		}
		word += "ay";
	}

	return word;
}

void PigLatin::encodeFile(const std::string& inFilePath, const std::string& outFilePath)
{
	ifs.open(inFilePath);
	if (!ifs.is_open())
		throw std::string("Could not open '" + inFilePath + "'");

	ofs.open(outFilePath);
	if (!ofs.is_open())
		throw std::string("Could not open '" + outFilePath + "'");

	ifs.seekg(0, std::iostream::end);
	int64_t length = ifs.tellg();
	ifs.seekg(0, std::iostream::beg);

	std::string word;
	// Loop thru the file one word at a time.
	while(ifs >> word)
	{
		std::string front, back;
		// Clean up the word front and back, removing any non
		// alphabetical letters and store them for later.
		while (!std::isalpha(word.front()))
		{
			front += word.front();
			word.erase(0, 1);
		}
		while (!std::isalpha(word.back()))
		{
			back = word.back() + back;
			word.pop_back();
		}

		// Apply encoding rules to the word.
		obfuscateWord(word);

		ofs << (front + word + back);

		// Handle white spaces.
		auto nextChar = ifs.peek();
		while(nextChar != EOF && std::isspace(nextChar))
		{
			ifs.get();
			ofs << static_cast<char>(nextChar);
			nextChar = ifs.peek();
		}
	}

	// Ensure that the buffer has been written.
	ofs.flush();
}
