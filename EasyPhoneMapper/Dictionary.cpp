#include "stdafx.h"
#include "Dictionary.h"
#include "Utils.h"
#include "FileException.h"

using namespace std;
using namespace Aconex;

CDictionary::CDictionary()
{
}

CDictionary::~CDictionary()
{
}

CDictionary::CDictionary(const MultiMapStringString& mapDict, const MultiMapCharChar& mapAlphaToNum)
	: m_mapDictionary(mapDict),
	m_mapAlphaToNum(mapAlphaToNum)
{
}

/*
Initialize the dictionary. Try loading the Alpha numeric data into memory.
*/
bool CDictionary::Init(const string& strDictFile, const string& strAlphaFile)
{
	bool bRetVal = false;
	try
	{
		if (SetAlphaNumericMapping(strAlphaFile))
		{
			SetString setWordList;
			GetWordListFromDictFile(strDictFile, setWordList);

			for (auto it : setWordList)
				AddWordToDictionary(it);

			bRetVal = true;
		}
	}
	catch (CFileException ex)
	{
		cout << "Init failed. " << ex.what();
	}

	return bRetVal;
}

/*
This function sets AlphaNmeric Map which has alphabets as keys and numbers as its values
 */
bool CDictionary::SetAlphaNumericMapping(const std::string& strAlphaFile)
{
	bool bRetVal = false;
	ifstream inFile(ALPHA_NUMERIC_FILE, ifstream::in);
	if (inFile)
	{
		bRetVal = true;
		while (!inFile.eof())
		{
			string strLine;
			getline(inFile, strLine);
			// tokenize numbers and characterlist
			VectorString vTokens;
			if (Utils::Tokenize(strLine, ' ', vTokens) > 1)
			{
				// tokenize characters
				VectorString vChars;
				Utils::Tokenize(vTokens[1], ',', vChars);
				for (auto it : vChars)
					m_mapAlphaToNum.insert(PairCharChar(toupper(it.at(0)), vTokens[0].at(0)));
			}
		}

		inFile.close();
	}
	else
	{
		string strMessage = "Error opening file: " + strAlphaFile;
		throw CFileException(strMessage);
	}

	return bRetVal;
}

/*
Read a dict file to load the word list
*/
size_t CDictionary::GetWordListFromDictFile(const std::string& strFileName, SetString& setWordList)
{
	ifstream inFile(strFileName, ifstream::in);

	setWordList.clear();
	if (inFile)
	{
		while (!inFile.eof())
		{
			string strWord;
			getline(inFile, strWord);
			setWordList.insert(strWord);
		}

		inFile.close();
	}
	else
	{
		string strMessage = "Error opening file: " + strFileName;
		throw CFileException(strMessage);
	}

	return setWordList.size();
}

/*
Add a given word to the dictionary. Generate key for the given word
based on number map and then insert it into the map.
*/
void CDictionary::AddWordToDictionary(const string& strWord)
{
	// Sanitize the string and make it conform to our requirements.
	string strWordCopy = Utils::InspectAndSanitizeString(strWord);

	// Make a number from a word and adds as a key in a dictionary
	string strNumKey;
	for (auto itChar : strWordCopy)
	{
		auto itNum = m_mapAlphaToNum.find(itChar);
		if (itNum != m_mapAlphaToNum.end())
			strNumKey += itNum->second;
	}
	m_mapDictionary.insert(PairStringString(strNumKey, strWordCopy));
}

/*
Return list of unique keys. Since a multi-map is used, returning a unique
set allows easier iteration on a unique set.*/
size_t CDictionary::GetUniqueKeys(SetString& setOutKeys) const
{
	setOutKeys.clear();

	for (auto it : m_mapDictionary)
		setOutKeys.insert(it.first);

	return setOutKeys.size();
}

/*
Return the list of values that occur for a given key.
*/
size_t CDictionary::GetMatchedEntries(const std::string& strKey, SetString& setOutMatches) const
{
	setOutMatches.clear();

	const auto valueList = m_mapDictionary.equal_range(strKey);
	for (auto it = valueList.first; it != valueList.second; ++it)
		setOutMatches.insert(it->second);

	return setOutMatches.size();
}
