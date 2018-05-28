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
		bool Init(std::string* pDictFile = nullptr);
		std::size_t GetUniqueKeys(SetString& setOutKeys);
		std::size_t GetMatchedEntries(const std::string& strKey, SetString& setOutMatches);

	private:
		CDictionary(const CDictionary&) = delete;
		CDictionary& operator=(const CDictionary&) = delete;
		CDictionary();
		CDictionary(const MultiMapStringString& mapDictMap);

		bool SetAlphaNumericMapping();
		std::size_t GetWordListFromDictFile(const std::string& strFileName, SetString& setWordList);
		void SanitizeString(std::string & strWord);
		void AddWordToDictionary(std::string strWord);

		// Members
		static CDictionary* m_sInstance;
		MultiMapStringString m_mapDictionary;
		MultiMapCharChar m_mapAlphaToNum;
	};
}
