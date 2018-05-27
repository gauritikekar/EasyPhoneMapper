#include "stdafx.h"
#include "Dictionary.h"

using namespace Aconex;
using namespace std;

CDictionary::CDictionary()
{
}

CDictionary::~CDictionary()
{
}

CDictionary::CDictionary(const MultiMapStringString& mDictMap)
{
}

CDictionary* CDictionary::instance = NULL;

CDictionary* CDictionary::getInstance()
{
	if (instance == NULL)
	{
		instance = new CDictionary();
	}
	return instance;
}

bool CDictionary::Init(const std::string* pDictFile)
{
	return false;
}

SetString&& CDictionary::GetUniqueKeys()
{
	SetString set;
	return move(set);
}

SetString&& CDictionary::GetMatchedEntries(const std::string& strKey)
{
	SetString set;
	return move(set);
}
