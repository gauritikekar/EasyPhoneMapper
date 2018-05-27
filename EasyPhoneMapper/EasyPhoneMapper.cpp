// EasyPhoneMapper.cpp : Defines the entry point for the command line application.
//

#include "stdafx.h"
#include "TestDictionary.h"
#include "TestGenerator.h"
#include "TestFailedException.h"

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
		cout << "Test case failed, Details: " << e.what();
		bRet = false;
	}
	return bRet;
}