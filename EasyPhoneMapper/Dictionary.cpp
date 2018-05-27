#include "stdafx.h"
#include "Dictionary.h"

using namespace std;
using namespace Aconex;

CDictionary::CDictionary()
{
}

CDictionary::~CDictionary()
{
}

CDictionary::CDictionary(const MultiMapStringString& mapDict) : m_mapNumToWordMap(mapDict)
{
}

CDictionary* CDictionary::m_sInstance = nullptr;

CDictionary* CDictionary::GetInstance()
{
	if (m_sInstance == NULL)
	{
		m_sInstance = new CDictionary();
	}
	return m_sInstance;
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
