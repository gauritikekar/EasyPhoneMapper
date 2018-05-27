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
		SetString&& ProcessNumber(const std::string& strNumber);
	protected:
		virtual bool Validate(const std::string& strNumber);

	};
}
