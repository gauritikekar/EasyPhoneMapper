#pragma once
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#define ALPHA_NUMERIC_FILE		".\\Data\\alphanum.txt"
#define DICTIONARY_FILE			".\\Data\\dictionary.txt"
#define MAX_CONSECUTIVE_DIGITS	(1)
#define CHAR_SEPARATOR			'-'
#define USER_DICT_FILE			"-d"
#define USER_INPUT_FILE			"-i"
#define USER_NUM_PREFIX			"-p"
#define HELP_SWITCH				"-h"
#define HELP_SWITCH_FULL		"-help"

namespace Aconex
{
	typedef std::multimap<std::string, std::string> MultiMapStringString;
	typedef std::map<std::string, std::string> MapStringString;
	typedef std::pair<std::string, std::string> PairStringString;
	typedef std::multimap<char, char> MultiMapCharChar;
	typedef std::pair<char, char> PairCharChar;
	typedef std::set<std::string> SetString;
	typedef std::vector<std::string> VectorString;
}
