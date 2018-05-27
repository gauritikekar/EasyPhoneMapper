#pragma once
namespace Aconex
{
	class CTestGenerator
	{
	public:
		CTestGenerator();
		~CTestGenerator();
		void RunAllTests();

		// Individual tests
		void TestProcessNumber();
		void TestValidate();

	};
}
