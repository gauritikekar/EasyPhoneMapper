#include "stdafx.h"
#include "Generator.h"
#include "Dictionary.h"
#include "Utils.h"

using namespace std;
using namespace Aconex;

CGenerator::CGenerator(const CDictionary& rDict)
	:m_rDict(rDict)
{
}

CGenerator::~CGenerator()
{
}

/*
Process the given number and return combinations that exist in dictionary.
*/
size_t CGenerator::ProcessNumber(const string& strNumber, SetString& setOutCombinations)
{
	setOutCombinations.clear();

	// Sanitize the number
	string strNumberCopy = Utils::InspectAndSanitizeString(strNumber);

	// Get all possible combinations of the given number by looking up the dictionary.
	GeneratePossibleWords(strNumberCopy, setOutCombinations);

	// Validate the generated word-list against our required grammar.
	for (auto it = setOutCombinations.begin(); it != setOutCombinations.end();)
	{
		if (!Validate(*it))
			setOutCombinations.erase(it++);
		else
			it++;
	}
	return setOutCombinations.size();
}

/*
Process the given number and return possible acceptable combinations for it.
*/
std::size_t CGenerator::GeneratePossibleWords(const std::string& strNumber, SetString& setOutCombinations)
{
	// Push the provided number into the reference word list container.
	VectorString vWordList;
	vWordList.push_back(strNumber);

	// Get the unique set of lookup keys. This is required since we hold
	// the keys in a multimap.
	SetString setUniqueKeys;
	m_rDict.GetUniqueKeys(setUniqueKeys);

	// Loop till there are no more replacements to be made.
	VectorString tempContainer;
	static string chSeparator(1, CHAR_SEPARATOR);
	while (1)
	{
		bool bFound = false;
		int i = 0;
		for (auto itWrd : vWordList)
		{
			for (auto itKey : setUniqueKeys)
			{
				// Check if the given word combination exists in the provided number.
				size_t iPos = itWrd.find(itKey);
				if (iPos != -1)
				{
					// If exists, get the list of strings that are possible variations using this key value.
					SetString setMatchedValues;
					m_rDict.GetMatchedEntries(itKey, setMatchedValues);

					// Replace key with matching string entries.
					for (auto itVal : setMatchedValues)
					{
						string tempStr;
						bFound = true;

						size_t iRight = itKey.size() + iPos;
						if (iPos > 0)
							tempStr = vWordList[i].substr(0, iPos) + chSeparator;

						tempStr += itVal;

						if (iRight < vWordList[i].size())
							tempStr += chSeparator + vWordList[i].substr(iRight, vWordList[i].size() - iRight);

						tempContainer.push_back(tempStr);
					}
				}
			}
			i++;
		}

		// Store the accumulated list into the reference container
		vWordList = tempContainer;
		tempContainer.clear();

		string chTwiceSeparator = chSeparator + chSeparator;
		for (auto it : vWordList)
		{
			// Trim double inserts of '-' in the logic above.
			for (size_t i = 0; (i = it.find(chTwiceSeparator, i)) != std::string::npos; i += chSeparator.size())
				it.replace(i, chTwiceSeparator.size(), chSeparator);

			setOutCombinations.insert(it);
		}

		if (!bFound)
			break;
	}

	return setOutCombinations.size();
}

/*
This function validates the number-word to see if there is any consecutive digit
*/
bool CGenerator::Validate(const std::string& strNumber)
{
	bool bRet = true;

	// Requirement 1: No two consecutive digits. Break if that is the case.
	int iDigitCntr = 0;
	for (auto itChar : strNumber)
	{
		if (isdigit(itChar) != 0)
			iDigitCntr++;
		else
			iDigitCntr = 0;

		if (iDigitCntr > MAX_CONSECUTIVE_DIGITS)
		{
			bRet = false;
			break;
		}
	}
	return bRet;
}
