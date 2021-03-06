#include "stdafx.h"
#include "Utils.h"
#include <sstream>
using namespace std;

size_t Aconex::Utils::Tokenize(string strInput, char chDelim, VectorString& vTokens)
{
	vTokens.clear();
	istringstream iss(strInput);
	string c;
	while (getline(iss, c, chDelim))
		vTokens.push_back(c);
	return vTokens.size();
}

/*
This function sanitizes the provided input for spaces and punctuation marks
*/
string Aconex::Utils::InspectAndSanitizeString(const string& strInput)
{
	string strChecked(strInput);

	// 1 - Space and punctuation marks are not allowed in the input string.
	static string strInvalidChars = { ';', ':','.',',','\"','!','?','[',']','(',')','-','\'','{','}','/', ' ' };
	Utils::RemoveChar(strChecked, strInvalidChars);

	// 2- All characters are in upper case.
	Utils::ToUpper(strChecked);

	return strChecked;
}

void Aconex::Utils::RemoveChar(string& strWord, const string& strChars)
{
	for (size_t i = 0; i < strChars.size(); ++i) {
		strWord.erase(remove(strWord.begin(), strWord.end(), strChars[i]), strWord.end());
	}
}

void Aconex::Utils::ToUpper(std::string& strWord)
{
	for (size_t i = 0; i<strWord.size(); i++)
		strWord[i] = toupper(strWord[i]);
}
