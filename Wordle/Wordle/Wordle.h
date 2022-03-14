#pragma once
enum class BackgroundColor;
struct GuessWord;

#define LetterLimit 5 
#define GuessLimit 6 

int main();

class Wordle
{
public:
	Wordle(){};
	void RunGame();

private:

	void CheckPlayAgain(string& targetWord, ifstream& inWords, HashSet* lines, int linesNum);

	void CheckGameOver(GuessWord& tempGuessWord, string& targetWord);

	void PrintGameState(vector<GuessWord>& guessWords);

	void AddGuessWordToCollection(GuessWord& tempGuessWord, string& input, BackgroundColor  backColor[5], vector<GuessWord>& guessWords);

	void ColorMatchingLetters(BackgroundColor  backColor[5], string& input, string& targetWord);

	bool AlreadyCheckedLetter(int checkedCount, int* checkLetters, int inChar);

	bool ContainsDuplicates(int g, int inChar, string& targetWord);

	bool IsValidInput(string& input, HashSet* lines);


	bool gameIsActive = true;
	bool gameIsOver = false;
	string input;
	vector<GuessWord> guessWords;
};
