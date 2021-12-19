/*
 * PigLatin.cpp
 *
 *  Created on: Dec 17, 2021
 *      Author: magnus
 */

#include "PigLatin.h"

PigLatin::PigLatin(std::string filePath) :
	fs(filePath)
{
	if (!fs.is_open())
		throw std::string("Could not open '" + filePath + "'");
}

PigLatin::~PigLatin()
{
	if (fs.is_open())
	{
		fs.close();
	}
}

