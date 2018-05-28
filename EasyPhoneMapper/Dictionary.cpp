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

CDictionary::CDictionary(const MultiMapStringString& mapDict) : m_mapDictionary(mapDict)
{
}

CDictionary* CDictionary::m_sInstance = nullptr;

CDictionary* CDictionary::GetInstance()
{
	if (!m_sInstance)
	{
		m_sInstance = new CDictionary();
	}
	return m_sInstance;
}

bool CDictionary::Init(std::string* pDictFile/*=nullptr*/)
{
	static string dictFile(DICTIONARY_FILE);

	bool bRetVal = false;
	if (SetAlphaNumericMapping())
	{
		// If parameter is null then load default dictionary
		if (!pDictFile)
			pDictFile = &dictFile;

		SetString setWordList;
		try
		{
			GetWordListFromDictFile(*pDictFile, setWordList);

			for (auto it : setWordList)
				AddWordToDictionary(it);

			bRetVal = true;
		}
		catch (CFileException ex)
		{
			cout << "Init failed. " << ex.what();
		}
	}
	return bRetVal;
}

/*
This function sets AlphaNmeric Map which has alphabets as keys and numbers as its values
 */
bool CDictionary::SetAlphaNumericMapping()
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
		string strMessage = "Error opening file: " + string(ALPHA_NUMERIC_FILE);
		throw CFileException(strMessage);
	}

	return bRetVal;
}

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

void CDictionary::AddWordToDictionary(string strWord)
{
	string strNumKey;

	SanitizeString(strWord);
	// Make a number from a word and adds as a key in a dictionary
	for (auto itChar : strWord)
	{
		auto itNum = m_mapAlphaToNum.find(itChar);
		if (itNum != m_mapAlphaToNum.end())
			strNumKey += itNum->second;
	}
	m_mapDictionary.insert(PairStringString(strNumKey, strWord));
}
void CDictionary::SanitizeString(std::string & strWord)
{
	Utils::Remove(strWord, ' ');
	Utils::Remove(strWord, '.');
	Utils::Remove(strWord, '-');
	Utils::ToUpper(strWord);
}

size_t CDictionary::GetUniqueKeys(SetString& setOutKeys)
{
	setOutKeys.clear();

	for (auto it : m_mapDictionary)
		setOutKeys.insert(it.first);

	return setOutKeys.size();
}

size_t CDictionary::GetMatchedEntries(const std::string& strKey, SetString& setOutMatches)
{
	setOutMatches.clear();

	MultiMapStringString::_Pairii valueList = m_mapDictionary.equal_range(strKey);
	for (auto it = valueList.first; it != valueList.second; ++it)
		setOutMatches.insert(it->second);

	return setOutMatches.size();
}
