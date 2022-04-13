#pragma once

struct HashSet;


class StringUtility
{
public:
	StringUtility() {};

	// feedback: Here however static style is fine,
	// as utility class instance is just a boilerplate that can be avoided. It's common to have static utility functions.
	// However I'd move IsValidWord and also GetRandomWord to the HashSet class, as those functions still require an instance of HashSet.. So it is
	// arguably a method of that class.
	static bool IsValidWord(HashSet* lines, string& input);

	static string stringToUpper(string input);

	static string GetRandomWord(ifstream& inWords, HashSet* lines, int linesNum);

	static HashSet* GetWordsInFile(ifstream& inWords, int& linesNum);

};



