#pragma once

struct HashSet;

bool IsValidWord(HashSet* lines, string& input);

string stringToUpper(string input);

string GetRandomWord(ifstream& inWords, HashSet* lines, int linesNum);

HashSet* GetWordsInFile(ifstream& inWords, int& linesNum);