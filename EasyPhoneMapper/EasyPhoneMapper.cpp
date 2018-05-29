// EasyPhoneMapper.cpp : Defines the entry point for the command line application.
//

#include "stdafx.h"
#include "Dictionary.h"

// Test support
#include "Tests\TestFailedException.h"
#include "Tests\TestDictionary.h"
#include "Tests\TestGenerator.h"

using namespace std;
using namespace Aconex;

// Forward Declaration
bool RunTests();

int main()
{
#ifdef _DEBUG
	if (!RunTests())
		return -1;
#endif // _DEBUG

	return 0;
}

bool RunTests()
{
	bool bRet = true;
	try
	{
		CTestDictionary().RunAllTests();
		CTestGenerator().RunAllTests();
	}
	catch (CTestFailedException e)
	{
		cout << "Test case failed. Details: " << e.what();
		bRet = false;
	}
	return bRet;
}
