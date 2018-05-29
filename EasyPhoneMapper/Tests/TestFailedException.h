#pragma once
#include "AconexException.h"

namespace Aconex
{
	class CTestFailedException : public CAconexException
	{
	public:
		explicit CTestFailedException(const char* message) :CAconexException(message) {}

		explicit CTestFailedException(const std::string& message) : CAconexException(message) {}
	};
}