#pragma once
#include <exception>
#include <string>

namespace Aconex
{
	class CTestFailedException : public std::exception
	{
	public:
		explicit CTestFailedException(const char* message) :m_strMsg(message) {}

		explicit CTestFailedException(const std::string& message) : m_strMsg(message) {}

		virtual ~CTestFailedException() throw() {}

		virtual const char* what() const throw ()
		{
			return m_strMsg.c_str();
		}
	protected:
		std::string m_strMsg;
	};
}