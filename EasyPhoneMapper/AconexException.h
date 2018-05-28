#pragma once
#include <exception>
#include <string>

class CAconexException :public std::exception
{
public:
	explicit CAconexException(const char* message) :m_strMsg(message) {}

	explicit CAconexException(const std::string& message) : m_strMsg(message) {}

	virtual ~CAconexException() throw() {}

	virtual const char* what() const throw ()
	{
		return m_strMsg.c_str();
	}
protected:
	std::string m_strMsg;
};
