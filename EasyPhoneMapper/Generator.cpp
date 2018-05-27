#include "stdafx.h"
#include "Generator.h"

using namespace Aconex;

CGenerator::CGenerator()
{
}

CGenerator::~CGenerator()
{
}

VectorString&& CGenerator::ProcessNumber(const std::string& strNumber)
{
	VectorString vec;
	return move(vec);
}

bool CGenerator::Validate(const std::string& strNumber)
{
	return false;
}
