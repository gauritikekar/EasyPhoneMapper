#pragma once
#include "Constants.h"

namespace Aconex
{
	class CGenerator
	{
	public:
		CGenerator();
		~CGenerator();
		VectorString&& ProcessNumber(const std::string& strNumber);
	protected:
		virtual bool Validate(const std::string& strNumber);

	};
}
