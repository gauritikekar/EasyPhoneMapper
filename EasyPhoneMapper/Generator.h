#pragma once
#include "Constants.h"

namespace Aconex
{
	// Forward declaration
	class CTestGenerator;
	class CDictionary;

	class CGenerator
	{
		// Unit testing support
		friend class CTestGenerator;

	public:
		CGenerator(const CDictionary& rDict);
		~CGenerator();
		std::size_t ProcessNumber(const std::string& strNumber, SetString& setOutCombinations);

	protected:
		virtual bool Validate(const std::string& strNumber);

	private:
		std::size_t GeneratePossibleWords(const std::string& strNumber, SetString& setOutCombinations);

	private:
		const CDictionary& m_rDict;
	};
}