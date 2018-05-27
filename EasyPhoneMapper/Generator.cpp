#include "stdafx.h"
#include "Generator.h"

using namespace Aconex;

CGenerator::CGenerator()
{
}

CGenerator::~CGenerator()
{
}

SetString&& CGenerator::ProcessNumber(const std::string& strNumber)
{
	SetString setCombinations;
	return move(setCombinations);
}

bool CGenerator::Validate(const std::string& strNumber)
{
	return false;
}
