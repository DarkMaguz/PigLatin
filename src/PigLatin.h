/*
 * PigLatin.h
 *
 *  Created on: Dec 17, 2021
 *      Author: magnus
 */

#ifndef SRC_PIGLATIN_H_
#define SRC_PIGLATIN_H_

#include <fstream>
#include <string>
#include <string_view>

#include "LangTypes.h"

class PigLatin
{
	public:
		PigLatin(const lt::lang_t& lang);
		virtual ~PigLatin();

		void encodeFile(const std::string& inFilePath, const std::string& outFilePath);

	private:
		std::string& obfuscateWord(std::string& word) const;
		std::ifstream ifs;
		std::ofstream ofs;

		const lt::lang_t language;
		inline static auto booleanVCMap = lt::makeVCMap();
};


#endif /* SRC_PIGLATIN_H_ */
