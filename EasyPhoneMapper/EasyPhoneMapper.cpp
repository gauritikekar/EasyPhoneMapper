#include "stdafx.h"
#include "EasyPhoneMapper.h"
#include "Generator.h"
#include "Constants.h"

using namespace std;
using namespace Aconex;

/*
Init the class, parse command line arguments and load the dictionary file
*/
bool CEasyPhoneMapper::Init(int argc, char* argv[])
{
	// 1- Process the command line arguments. Populate member variables.
	if (!ProcessCommandLineArgs(argc, argv))
		return false;

	// 2- Load dictionary data. 
	if (!LoadDictFile())
		return false;

	return true;
}
/*
Function to process user inputs either via console or via an input file.
*/
int CEasyPhoneMapper::ProcessInput()
{
	if (m_strInputFile.empty())
	{
		string strChoice;
		do
		{
			string strNumber;
			cout << "Input phone number:";
			cin >> strNumber;

			PrintNumberCombinations(strNumber);

			cout << "Try another phone number [Y/N]?";
			cin >> strChoice;

		} while (strChoice == "Y" || strChoice == "y");
	}
	else
	{
		ifstream inFile(m_strInputFile, ifstream::in);
		if (!inFile)
		{
			cout << "Opening input file failed. File " << m_strInputFile << " is invalid.";
			return -1;
		}
		else
		{
			while (!inFile.eof())
			{
				string strNumber;
				getline(inFile, strNumber);
				PrintNumberCombinations(strNumber);
			}
		}
	}

	return 0;
}

///////////////////////////////////////////////////////////////////////////////
// Private methods
///////////////////////////////////////////////////////////////////////////////

/*
Load provided file in a dictionary container
*/
bool CEasyPhoneMapper::LoadDictFile()
{
	// Init Dictionary - Either default or user defined.
	if (m_strDictFile.empty())
		m_strDictFile = DICTIONARY_FILE;
	if (!m_dict.Init(m_strDictFile, ALPHA_NUMERIC_FILE))
		return false;
	return true;
}

/*
Parse command line arguments and store the result in the class
*/
bool CEasyPhoneMapper::ProcessCommandLineArgs(int argc, char* argv[])
{
	// Help switch
	if (argc > 1 && (string(argv[1]) == HELP_SWITCH || string(argv[1]) == HELP_SWITCH_FULL))
	{
		PrintUsage();
		return false;
	}

	m_strDictFile = m_strInputFile = m_strPrefix = string();

	MapStringString mapCmdArgs;
	for (int i = 1; i < argc - 1; i += 2)
		mapCmdArgs.insert(PairStringString(argv[i], argv[i + 1]));

	// Dict File
	auto it = mapCmdArgs.find(USER_DICT_FILE);
	if (it != mapCmdArgs.end())
		m_strDictFile = it->second;

	// Input File
	it = mapCmdArgs.find(USER_INPUT_FILE);
	if (it != mapCmdArgs.end())
		m_strInputFile = it->second;

	// Prefix Number
	it = mapCmdArgs.find(USER_NUM_PREFIX);
	if (it != mapCmdArgs.end())
	{
		m_strPrefix = it->second;
		if (m_strPrefix.size() > 0 && m_strPrefix[m_strPrefix.size() - 1] != CHAR_SEPARATOR)
			m_strPrefix += CHAR_SEPARATOR;
	}

	return true;
}

/*
Print the possible combinations for a number to the screen.
*/
void CEasyPhoneMapper::PrintNumberCombinations(const string& strNumber)
{
	CGenerator obGenerator(m_dict);
	SetString setOutCombinations;
	if (obGenerator.ProcessNumber(strNumber, setOutCombinations) > 0)
	{
		cout << "Found \"" << setOutCombinations.size() << "\" acceptable combinations for phone number " << strNumber << " are:" << endl;
		for (auto it : setOutCombinations)
			cout << m_strPrefix << it << endl;
	}
	else
	{
		cout << "No valid combinations found for phone number " << strNumber << "." << endl;
	}
}

void CEasyPhoneMapper::PrintUsage()
{
	cout << "----" << endl;
	cout << "Generate possible permutations of a phone number that are easy to remember and dial." << endl;
	cout << "e.g. 1-800-FLOWERS" << endl << endl;
	cout << "The program accepts user input via the console or a user specified text file." << endl;
	cout << "A default dictionary can be used and available inside the .\\Data folder." << endl << endl;
	cout << "Usage: EasyPhoneMapper.exe [-h|-help] [[-d] dictionaryFile] [[-i] inputFile] [[-p] prefix string]" << endl;
	cout << endl << "Where," << endl;
	cout << "-h|help\tDisplays this help text." << endl;
	cout << "-i     \tText file containing one phone number per line. Useful for batch processing." << endl;
	cout << "-d     \tUser specified dictionary file with one word per line." << endl;
	cout << "-p     \tThe fix number to prefix a given phone number. e.g. '1-800'" << endl;
	cout << "----" << endl;
}
