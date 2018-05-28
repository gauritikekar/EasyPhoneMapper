#pragma once
#include "Constants.h"

namespace Aconex
{
	// Forward declaration
	class CTestGenerator;

	class CGenerator
	{
		// Unit testing support
		friend class CTestGenerator;

	public:
		CGenerator();
		~CGenerator();
		std::size_t ProcessNumber(const std::string& strNumber, SetString& setOutCombinations);
	protected:
		virtual bool Validate(const std::string& strNumber);

	};
}
