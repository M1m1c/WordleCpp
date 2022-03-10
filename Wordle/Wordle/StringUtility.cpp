#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "HashSet.h"
#include "StringUtility.h";


bool IsValidWord(HashSet* lines, string& input)
{
	bool isValidWord = false;
	/*for (auto var : lines)
	{
		auto compLine = stringToUpper(var);
		auto compInput = stringToUpper(input);
		if (compInput == compLine) {
			isValidWord = true;
			break;
		}
	}*/

	auto tempWord = HashSet::Find(lines, input);
	if (tempWord != NULL ) 
	{
		isValidWord = true;
	}
	return isValidWord;
}

string stringToUpper(string input)
{
	string retval;

	for (auto var : input)
	{
		retval += toupper(var);
	}

	return retval;
}

//TODO this can return null find a way to get a random number that is not null
string GetRandomWord(ifstream& inWords, HashSet* lines, int linesNum)
{
	srand(time(0));
	int randomNumber = rand() % linesNum;

	return *lines->items[randomNumber]->key;
}

HashSet* GetWordsInFile(ifstream& inWords, int& linesNum)
{
	HashSet* lines = HashSet::CreateSet(CAPACITY);
	string line;


	while (getline(inWords, line))
	{
		linesNum++;
		HashSet::Add(lines, &line);
	}

	return lines;
}