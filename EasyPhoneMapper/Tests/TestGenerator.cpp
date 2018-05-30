#include "stdafx.h"
#include "TestGenerator.h"
#include "Generator.h"
#include "TestFailedException.h"
#include "Dictionary.h"
#include "TestData.h"

using namespace std;
using namespace Aconex;

CTestGenerator::CTestGenerator()
{
}

CTestGenerator::~CTestGenerator()
{
}

void CTestGenerator::RunAllTests()
{
	TestProcessNumber();
	TestValidate();
}

/*
This function tests ProcessNumber function of CGenerator class to return
all valid matched entries for the given number.
*/
void CTestGenerator::TestProcessNumber()
{
	VectorString vPhoneNumbers =
	{
	"1228 9227",
	"1228.922",
	"228-922",
	"2277",
	"96753",
	"3283;9667",
	"",
	"2",
	"0367\"8863",
	"732732"
	};

	short arrCombinationCount[] = { 2,0,0,2,1,2,0,0,1,4 };

	SetString setCombinations[] =
	{
		{ "1-CAT-9-CAR","1-BAT-9-CAR" },
		{},
		{},
		{ "CAR-7", "CARS" },
		{ "WORLD" },
		{ "DATE-ZOO-7", "FATE-ZOO-7" },
		{},
		{},
		{ "0-FORTUNE" },
		{ "SEA-PEA", "PEA-SEA", "PEA-PEA", "SEA-SEA"}
	};

	// Init test dict
	CDictionary testDict(TestData::s_mapDict, TestData::s_mapAlphaNumeric);

	CGenerator testGen(testDict);

	unsigned short n = 0;
	for (auto itNum : vPhoneNumbers)
	{
		// Check output size matched expectations
		SetString setOutCombinations;
		if (testGen.ProcessNumber(itNum, setOutCombinations) != arrCombinationCount[n])
			throw CTestFailedException("TestProcessNumber: Combination count invalid.");

		// Check contents match
		for (const auto it : setCombinations[n])
		{
			if (setOutCombinations.find(it) == setOutCombinations.end())
				throw CTestFailedException("TestProcessNumber: List incomplete.");
		}

		n++;
	}
}

/*
This function tests Validate function of CGenerator class to check
if the given combination is valid or not.
*/
void CTestGenerator::TestValidate()
{
	VectorString vPhoneNumbers =
	{
		"1-CAT-9-CAR",
		"1-CAT-922",
		"BAT-922",
		"BAT",
		"96-SEA",
		"DATE-FATE-7"
	};

	bool bValidatedVal[] = { true, false, false, true, false, true };

	// Init test dict
	CDictionary testDict(TestData::s_mapDict, TestData::s_mapAlphaNumeric);

	CGenerator testGen(testDict);

	unsigned short n = 0;
	for (auto it : vPhoneNumbers)
	{
		// Check validity match
		if (testGen.Validate(it) != bValidatedVal[n++])
			throw CTestFailedException("TestValidate: Result mismatched.");
	}
}
