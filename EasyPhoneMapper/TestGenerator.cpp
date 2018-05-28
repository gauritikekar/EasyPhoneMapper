#include "stdafx.h"
#include "TestGenerator.h"
#include "Generator.h"
#include "TestFailedException.h"

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
		"227",
		"96753"
	};

	short arrCombinationCount[] = { 2,0,0,1,0 };

	SetString setCombinations[] =
	{
		{"1-CAT-9-CAR","1-BAT-9-CAR"},
		{},
		{},
		{"CAR"},
		{}
	};

	CGenerator testGen;

	unsigned short n = 0;
	for (auto it : vPhoneNumbers)
	{
		// Check output size matched expectations
		SetString setOutCombinations;
		if (testGen.ProcessNumber(it, setOutCombinations) != arrCombinationCount[n])
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
		"96-SEA"
	};

	bool bValidatedVal[] = { true, false, false, true, false };

	CGenerator testGen;

	unsigned short n = 0;
	for (auto it : vPhoneNumbers)
	{
		// Check validity match
		if (testGen.Validate(it) != bValidatedVal[n++])
			throw CTestFailedException("TestValidate: Result mismatched.");
	}
}
