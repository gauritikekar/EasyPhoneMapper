#pragma once
#include <string>
#include "Dictionary.h"

namespace Aconex
{
	class CEasyPhoneMapper
	{
	public:
		CEasyPhoneMapper() {}
		~CEasyPhoneMapper() {}
		
		bool Init(int argc, char* argv[]);
		int  ProcessInput();
	
	private:
		bool ProcessCommandLineArgs(int argc, char* argv[]);
		bool LoadDictFile();
		void PrintNumberCombinations(const std::string& strNumber);
		void PrintUsage();

	private:
		CDictionary m_dict;
		std::string m_strDictFile;
		std::string m_strInputFile;
		std::string m_strPrefix;
	};
}
