#include "stdafx.h"
#include "Utils.h"

using namespace std;

size_t Aconex::Utils::Tokenize(string strInput, char chDelim, VectorString& vTokens)
{
	vTokens.clear();
	char* chNextToken = nullptr;
	char *chToken = strtok_s((char*)strInput.c_str(), &chDelim, &chNextToken);
	while (chToken)
	{
		vTokens.push_back(chToken);
		chToken = strtok_s(NULL, &chDelim, &chNextToken);
	}
	return vTokens.size();
}

void Aconex::Utils::Remove(std::string& strWord, const char& ch)
{
	remove(strWord.begin(), strWord.end(), ch);
}

void Aconex::Utils::ToUpper(std::string& strWord)
{
	for(auto it: strWord)
		toupper(it);
}
