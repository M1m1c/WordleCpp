#pragma once

bool IsValidWord(vector<string>& lines, string& input);

string stringToUpper(string input);

string GetRandomWord(ifstream& inWords, vector<string>& lines, int linesNum);

vector<string> GetWordsInFile(ifstream& inWords, int& linesNum);