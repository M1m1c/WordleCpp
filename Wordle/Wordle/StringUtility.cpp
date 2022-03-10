#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "StringUtility.h";


bool IsValidWord(vector<string>& lines, string& input)
{
	bool isValidWord = false;
	for (auto var : lines)
	{
		auto compLine = stringToUpper(var);
		auto compInput = stringToUpper(input);
		if (compInput == compLine) {
			isValidWord = true;
			break;
		}
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

string GetRandomWord(ifstream& inWords, vector<string>& lines, int linesNum)
{
	srand(time(0));
	int randomNumber = rand() % linesNum;

	return lines[randomNumber];
}

vector<string> GetWordsInFile(ifstream& inWords, int& linesNum)
{
	vector<string> lines;
	string line;


	while (getline(inWords, line))
	{
		linesNum++;
		lines.push_back(line);
	}

	return lines;
}