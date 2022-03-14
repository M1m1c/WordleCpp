#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "HashSet.h"
#include "StringUtility.h";


bool StringUtility::IsValidWord(HashSet* lines, string& input)
{
	bool isValidWord = false;
	auto upper = stringToUpper(input);
	auto tempWord = HashSet::Find(lines, &upper);
	if (tempWord != NULL ) 
	{
		isValidWord = true;
	}
	return isValidWord;
}

string StringUtility::stringToUpper(string input)
{
	string retval;

	for (auto var : input)
	{
		retval += toupper(var);
	}

	return retval;
}

string StringUtility::GetRandomWord(ifstream& inWords, HashSet* lines, int linesNum)
{
	srand(time(0));
	int randomNumber = rand() % linesNum;
	auto index = lines->indecies[randomNumber];
	return lines->items[index]->key;
}

HashSet* StringUtility::GetWordsInFile(ifstream& inWords, int& linesNum)
{
	HashSet* lines = HashSet::CreateSet(Capacity);
	string line;


	while (getline(inWords, line))
	{
		linesNum++;
		HashSet::Add(lines, line);
	}

	return lines;
}