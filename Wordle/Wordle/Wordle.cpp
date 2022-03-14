#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using std::ifstream;
#include "Color.h"
#include "StringUtility.h";
#include "GuessWord.cpp"
#include "Wordle.h"
#include "HashSet.h"


int main()
{
	Wordle game;
	game.RunGame();
}

void Wordle::RunGame()
{
	ifstream inWords;
	inWords.open("words.txt");
	if (!inWords) { return; }

	int linesNum = 0;
	HashSet* lines = StringUtility::GetWordsInFile(inWords, linesNum);

	string randWord = StringUtility::GetRandomWord(inWords, lines, linesNum);

	while (gameIsActive)
	{
		PrintGameState(guessWords);

		if (gameIsOver)
		{
			CheckPlayAgain(randWord, inWords, lines, linesNum);
			system("CLS");
			continue;
		}

		cout << "please type a five letter word:\n";
		cin >> input;

		if (!IsValidInput(input, lines)) { continue; }

		GuessWord tempGuessWord;
		BackgroundColor backColor[5];

		ColorMatchingLetters(backColor, input, randWord);

		AddGuessWordToCollection(tempGuessWord, input, backColor, guessWords);

		system("CLS");

		CheckGameOver(tempGuessWord, randWord);
	}
}

void Wordle::CheckPlayAgain(string& randWord, ifstream& inWords, HashSet* lines, int linesNum)
{
	cout << FOREGROUND(ForegroundColor::BrightYellow, "Would you like to play again y/n\n");
	cin >> input;
	if (input.size() > 0)
	{
		if (toupper(input[0]) == 'Y')
		{
			gameIsOver = false;
			guessWords.clear();
			randWord = StringUtility::GetRandomWord(inWords, lines, linesNum);
		}
		else if (toupper(input[0]) == 'N')
		{
			gameIsActive = false;
		}
	}
}

void Wordle::CheckGameOver(GuessWord& tempGuessWord, string& targetWord)
{
	if (StringUtility::stringToUpper(tempGuessWord.word) == StringUtility::stringToUpper(targetWord))
	{
		cout
			<< FOREGROUND(ForegroundColor::BrightGreen, "Congratulations you guessed correctly, the word was: ")
			<< FOREGROUND(ForegroundColor::BrightGreen, targetWord) << "\n";
		gameIsOver = true;
	}
	else if (guessWords.size() == GuessLimit)
	{
		cout
			<< FOREGROUND(ForegroundColor::BrightYellow, "GAME OVER, the correct word was: ")
			<< FOREGROUND(ForegroundColor::BrightYellow, targetWord) << "\n";
		gameIsOver = true;
	}
}

void Wordle::PrintGameState(vector<GuessWord>& guessWords)
{
	cout << "WORDLE\n";
	for (int i = 0; i < GuessLimit; i++)
	{
		if (guessWords.size() > 0 && guessWords.size() > i)
		{
			GuessWord& current = guessWords[i];
			for (int g = 0; g < LetterLimit; g++)
			{
				cout << BACKGROUND(current.letterColors[g], current.word[g]);
			}
		}
		else
		{
			for (int g = 0; g < LetterLimit; g++)
			{
				cout << "?";
			}
		}
		cout << "\n";
	}
}

void Wordle::AddGuessWordToCollection(GuessWord& tempGuessWord, string& input, BackgroundColor  backColor[5], vector<GuessWord>& guessWords)
{
	tempGuessWord.word = input;

	for (int i = 0; i < LetterLimit; i++)
	{
		tempGuessWord.letterColors[i] = backColor[i];
	}
	guessWords.push_back(tempGuessWord);
}

void Wordle::ColorMatchingLetters(BackgroundColor  backColor[5], string& input, string& targetWord)
{
	int checkLetters[5];
	int checkedCount = 0;
	for (int i = 0; i < LetterLimit; i++)
	{
		backColor[i] = BackgroundColor::None;
		auto inChar = toupper(input[i]);

		if (AlreadyCheckedLetter(checkedCount, checkLetters, inChar)) 
		{
			continue;
		}

		if (inChar == toupper(targetWord[i]))
		{
			backColor[i] = BackgroundColor::Green;
		}
		else
		{
			for (int g = 0; g < LetterLimit; g++)
			{
				if (inChar == toupper(targetWord[g]))
				{
					backColor[i] = BackgroundColor::Yellow;
				}
			}
		}

		if (ContainsDuplicates(i, inChar, targetWord) == false)
		{
			checkLetters[checkedCount] = inChar;
			checkedCount++;
		}
	}
}

bool Wordle::AlreadyCheckedLetter(int checkedCount, int* checkLetters, int inChar)
{
	bool retval = false;
	for (int g = 0; g < checkedCount; g++)
	{
		if (checkLetters[g] == inChar) {
			retval = true;
			break;
		}
	}
	return retval;
}

bool Wordle::ContainsDuplicates(int g, int inChar, string& targetWord)
{
	bool isDuplicate = false;
	for (int q = g + 1; q < LetterLimit; q++)
	{
		if (inChar == toupper(targetWord[q]))
		{
			isDuplicate = true;
		}
	}
	return isDuplicate;
}

bool Wordle::IsValidInput(string& input, HashSet* lines)
{

	if (input.size() != LetterLimit)
	{
		system("CLS");
		cout << FOREGROUND(ForegroundColor::BrightYellow, "Your input is not a five letter word! \n");
		return false;
	}

	if (!StringUtility::IsValidWord(lines, input))
	{
		system("CLS");
		cout << FOREGROUND(ForegroundColor::BrightYellow, "Your input is not a valid word! \n");
		return false;
	}

	return true;
}

