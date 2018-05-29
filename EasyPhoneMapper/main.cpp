#include "stdafx.h"
#include "EasyPhoneMapper.h"
// Test support
#include "Tests\TestFailedException.h"
#include "Tests\TestDictionary.h"
#include "Tests\TestGenerator.h"

using namespace std;
using namespace Aconex;

// Forward declaration
bool RunTests();

int main(int argc, char* argv[])
{
	// 1- Run unit tests - Debug Mode Only
#ifdef _DEBUG
	if (!RunTests())
		return -1;
#endif // _DEBUG

	// 2- Process command line arguments and init the mapper business 
	//    logic
	CEasyPhoneMapper obMapper;
	if (!obMapper.Init(argc, argv))
		return -1;

	// 3- Process and perform number translation.
	return obMapper.ProcessInput();
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
