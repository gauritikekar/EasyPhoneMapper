#pragma once
#include "AconexException.h"

namespace Aconex
{
	class CFileException : public CAconexException
	{
	public:
		explicit CFileException(const char* message) :CAconexException(message) {}

		explicit CFileException(const std::string& message) : CAconexException(message) {}
	};
}
