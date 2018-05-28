#pragma once
#include "Constants.h"

namespace Aconex
{
	namespace Utils
	{
		std::size_t Tokenize(std::string strInput, char chDelim, VectorString& vTokens);
		void Remove(std::string& strWord, const char& ch);
		void ToUpper(std::string& strWord);
	}
}