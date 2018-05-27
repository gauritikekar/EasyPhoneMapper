#pragma once
#include "Constants.h"

namespace Aconex
{
	// Forward declaration
	class CTestDictionary;

	class CDictionary
	{
		// Unit testing support
		friend class CTestDictionary;

	public:
		static CDictionary* GetInstance();
		~CDictionary();
		bool Init(const std::string* pDictFile = nullptr);
		SetString&& GetUniqueKeys();
		SetString&& GetMatchedEntries(const std::string& strKey);

	private:
		static CDictionary* m_sInstance;
		CDictionary(const CDictionary&) = delete;
		CDictionary& operator=(const CDictionary&) = delete;
		CDictionary();
		CDictionary(const MultiMapStringString& mapDictMap);

		MultiMapStringString m_mapNumToWordMap;
	};
}
