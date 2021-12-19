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

class PigLatin
{
	public:
		PigLatin(std::string filePath);
		virtual ~PigLatin();

	private:
		std::ifstream fs;
};

#endif /* SRC_PIGLATIN_H_ */
