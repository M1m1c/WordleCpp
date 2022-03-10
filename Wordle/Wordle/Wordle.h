#pragma once
enum class BackgroundColor;
struct GuessWord;

int main();

void CheckPlayAgain(string& targetWord, ifstream& inWords, HashSet* lines, int linesNum);

void CheckGameOver(GuessWord& tempGuessWord, string& targetWord);

void PrintGameState(vector<GuessWord>& guessWords);

void AddGuessWordToCollection(GuessWord& tempGuessWord, string& input, BackgroundColor  backColor[5], vector<GuessWord>& guessWords);

void ColorMatchingLetters(BackgroundColor  backColor[5], string& input, string& targetWord);

bool IsValidInput(string& input, HashSet* lines);





int letterLimit = 5;
int guessLimit = 6;
bool gameIsActive = true;
bool gameIsOver = false;
string input;
vector<GuessWord> guessWords;