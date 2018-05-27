#pragma once
#include "Constants.h"

namespace Aconex
{
	class CDictionary
	{
	public:
		static CDictionary* getInstance();
		~CDictionary();
		bool Init(const std::string* pDictFile = NULL);
		SetString&& GetUniqueKeys();
		SetString&& GetMatchedEntries(const std::string& strKey);

	private:
		static CDictionary* instance;
		CDictionary(const CDictionary&) = delete;
		CDictionary& operator=(const CDictionary&) = delete;
		CDictionary();
		CDictionary(const MultiMapStringString& mDictMap);

	};
}
