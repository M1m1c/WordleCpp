#pragma once
enum class BackgroundColor;
struct GuessWord;

int main();

void CheckPlayAgain(std::string& targetWord, std::ifstream& inWords, std::vector<std::string>& lines, int linesNum);

void CheckGameOver(GuessWord& tempGuessWord, std::string& targetWord);

vector<string> GetWordsInFile(ifstream& inWords, int& linesNum);

string GetTargetWord(ifstream& inWords, vector<string>& lines, int linesNum);
string stringToLower(string input);

void PrintGameState(std::vector<GuessWord>& guessWords);
void AddGuessWordToCollection(GuessWord& tempGuessWord, string& input, BackgroundColor  backColor[5], std::vector<GuessWord>& guessWords);
void ColorMatchingLetters(BackgroundColor  backColor[5], string& input, string& targetWord);

bool IsValidInput(string& input, vector<string>& lines);
bool IsValidWord(vector<string>& lines, string& input);


int letterLimit = 5;
int guessLimit = 6;
bool gameIsActive = true;
bool gameIsOver = false;
string input;
vector<GuessWord> guessWords;