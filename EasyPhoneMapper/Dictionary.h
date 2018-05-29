#pragma once
#include "Constants.h"

namespace Aconex
{
	// Forward declaration
	class CTestDictionary;
	class CTestGenerator;

	class CDictionary
	{
		// Unit testing support
		friend class CTestDictionary;
		friend class CTestGenerator;

	public:
		CDictionary();
		~CDictionary();
		bool Init(const std::string& strDictFile, const std::string& strAlphaFile);
		std::size_t GetUniqueKeys(SetString& setOutKeys) const;
		std::size_t GetMatchedEntries(const std::string& strKey, SetString& setOutMatches) const;

	private:
		CDictionary(const MultiMapStringString& mapDictMap, const MultiMapCharChar& mapAlphaToNum);

		bool SetAlphaNumericMapping(const std::string& strAlphaFile);
		std::size_t GetWordListFromDictFile(const std::string& strFileName, SetString& setWordList);
		void AddWordToDictionary(const std::string& strWord);

		// Members
		MultiMapStringString m_mapDictionary;
		MultiMapCharChar m_mapAlphaToNum;
	};
}
