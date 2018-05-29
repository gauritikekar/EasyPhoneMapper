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
		CDictionary();
		~CDictionary();
		bool Init(std::string* pDictFile = nullptr);
		std::size_t GetUniqueKeys(SetString& setOutKeys) const;
		std::size_t GetMatchedEntries(const std::string& strKey, SetString& setOutMatches) const;

	private:
		CDictionary(const MultiMapStringString& mapDictMap);

		bool SetAlphaNumericMapping();
		std::size_t GetWordListFromDictFile(const std::string& strFileName, SetString& setWordList);
		void SanitizeString(std::string & strWord);
		void AddWordToDictionary(const std::string& strWord);

		// Members
		MultiMapStringString m_mapDictionary;
		MultiMapCharChar m_mapAlphaToNum;
	};
}
