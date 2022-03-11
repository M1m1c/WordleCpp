#pragma once

struct HashSet;


class StringUtility
{
public:
	StringUtility() {};

	static bool IsValidWord(HashSet* lines, string& input);

	static string stringToUpper(string input);

	static string GetRandomWord(ifstream& inWords, HashSet* lines, int linesNum);

	static HashSet* GetWordsInFile(ifstream& inWords, int& linesNum);

};



