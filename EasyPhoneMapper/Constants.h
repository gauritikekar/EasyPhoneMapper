#pragma once
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#define ALPHA_NUMERIC_FILE		"alphanum.txt"
#define DICTIONARY_FILE			"dictionary.txt"

namespace Aconex
{
	typedef std::multimap<std::string, std::string> MultiMapStringString;
	typedef std::pair<std::string, std::string> PairStringString;
	typedef std::multimap<char, char> MultiMapCharChar;
	typedef std::pair<char, char> PairCharChar;
	typedef std::set<std::string> SetString;
	typedef std::vector<std::string> VectorString;
}
