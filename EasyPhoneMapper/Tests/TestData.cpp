#include "stdafx.h"
#include "TestData.h"

using namespace std;
using namespace Aconex;

// Map of a number to a known word
MultiMapStringString TestData::s_mapDict =
{
	{ "227", "CAR" },
	{ "2277", "CARS" },
	{ "96753", "WORLD" },
	{ "228", "BAT" },
	{ "228", "CAT" },
	{ "732", "SEA" },
	{ "732", "PEA" },
	{ "538837", "LETTER" },
	{ "966", "ZOO" },
	{ "3283", "DATE" },
	{ "3283", "FATE" },
	{ "3678863", "FORTUNE" },
	{ "7678", "POST" }
};

// Map of a set of characters to a number
MultiMapCharChar TestData::s_mapAlphaNumeric =
{
	{ 'A','2' },{ 'B','2' },{ 'C','2' },
	{ 'D','3' },{ 'E','3' },{ 'F','3' },
	{ 'G','4' },{ 'H','4' },{ 'I','4' },
	{ 'J','5' },{ 'K','5' },{ 'L','5' },
	{ 'M','6' },{ 'N','6' },{ 'O','6' },
	{ 'P','7' },{ 'Q','7' },{ 'R','7' },{ 'S','7' },
	{ 'T','8' },{ 'U','8' },{ 'V','8' },
	{ 'W','9' },{ 'X','9' },{ 'Y','9' },{ 'Y','7' }
};
