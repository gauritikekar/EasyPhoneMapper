#include "stdafx.h"
#include "TestDictionary.h"
#include "Dictionary.h"
#include "TestFailedException.h"

using namespace std;
using namespace Aconex;

static MultiMapStringString s_mapDict =
{
	{ "227", "CAR" },
	{ "96753", "WORLD" },
	{ "228", "BAT" },
	{ "228", "CAT" },
	{ "732", "SEA" }
};

CTestDictionary::CTestDictionary()
{

}

CTestDictionary::~CTestDictionary()
{
}

void CTestDictionary::RunAllTests()
{
	TestMatchedEntries();
	TestUniqueKeys();
}

/*
This function tests GetMatchedEntries function of CDictionary class to check
all valid matched entries for the given key.
*/
void CTestDictionary::TestMatchedEntries()
{
	string arrNumber[] = { "227","228","7324" };
	unsigned short arrOccurenceCount[] = { 1,2,0 };
	SetString setMatches[] =
	{
		{"CAR"},
		{"BAT","CAT"},
		{}
	};

	CDictionary testDict(s_mapDict);

	unsigned short n = 0;
	for (auto it : arrNumber)
	{
		SetString setOutMatches;
		testDict.GetMatchedEntries(it, setOutMatches);

		// Check output size matched expectations
		if (setOutMatches.size() != arrOccurenceCount[n])
			throw CTestFailedException("TestMatchedEntries: Size incorrect.");

		// Check contents match
		for (const auto it : setMatches[n])
		{
			if (setOutMatches.find(it) == setOutMatches.end())
				throw CTestFailedException("TestMatchedEntries: Match incomplete.");
		}

		n++;
	}
}

/*
This function tests GetUniqueKeys function of CDictionary class to
check all valid unique keys in a map
*/
void CTestDictionary::TestUniqueKeys()
{
	CDictionary testDict(s_mapDict);

	SetString setOutKeys;
	testDict.GetUniqueKeys(setOutKeys);

	if (setOutKeys.size() != 4)
		throw CTestFailedException("TestUniqueKeys: Unique count incorrect.");
}
