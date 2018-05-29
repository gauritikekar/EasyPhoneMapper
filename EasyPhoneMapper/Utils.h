#pragma once
#include "Constants.h"

namespace Aconex
{
	namespace Utils
	{
		std::size_t Tokenize(std::string strInput, char chDelim, VectorString& vTokens);
		std::string InspectAndSanitizeString(const std::string& strInput);
		void RemoveChar(std::string& strWord, const std::string& strChars);
		void ToUpper(std::string& strWord);
	}
}