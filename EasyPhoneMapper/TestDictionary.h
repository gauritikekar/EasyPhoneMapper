#pragma once
namespace Aconex
{
	class CTestDictionary
	{
	public:
		CTestDictionary();
		~CTestDictionary();
		void RunAllTests();

		// Individual tests
		void TestMatchedEntries();
		void TestUniqueKeys();
	};
}
