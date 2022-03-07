#pragma once
enum class BackgroundColor;
struct GuessWord;

int main();

vector<string> GetWordsInFile(ifstream& inWords, int& linesNum);

string GetTargetWord(ifstream& inWords, vector<string>& lines, int linesNum);
string stringToLower(string input);

void PrintGameState(std::vector<GuessWord>& guessWords);
void AddGuessWordToCollection(GuessWord& tempGuessWord, string& input, BackgroundColor  backColor[5], std::vector<GuessWord>& guessWords);
void ColorMatchingLetters(BackgroundColor  backColor[5], string& input, string& targetWord);

bool IsValidInput(string& input, vector<string>& lines);
bool IsValidWord(vector<string>& lines, string& input);


int letterLimit = 5;
bool gameIsActive = true;
string input;
vector<GuessWord> guessWords;