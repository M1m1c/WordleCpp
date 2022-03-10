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


//TODO fix so that duplicates of letters that dont exist in the target word dont get colored
int main()
{
	ifstream inWords;
	inWords.open("words.txt");
	if (!inWords) { return 1; }

	int linesNum = 0;
	HashSet* lines = GetWordsInFile(inWords, linesNum);

	cout << linesNum;
	//string temp = "stamp";
	//string temp2 = "bump";
	//HashSet* table = HashSet::CreateSet(CAPACITY);// CreateSet(CAPACITY);

	//HashSet::Add(table, &temp);
	//HashSet::Add(table, &temp2);
	//auto lemp = HashSet::Find(table , "bump");
	//if (lemp != NULL)
	//{
	//	cout << *lemp << "\n";
	//}


	////char temp[5] = {"stamp"};
	//const char* str = "stamp";
	//cout << strlen(str) << "\n";

	string randWord = "BENCH";// GetRandomWord(inWords, lines, linesNum);

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

void CheckPlayAgain(string& randWord, ifstream& inWords, HashSet* lines, int linesNum)
{
	cout << FOREGROUND(ForegroundColor::BrightYellow, "Would you like to play again y/n\n");
	cin >> input;
	if (input.size() > 0)
	{
		if (toupper(input[0]) == 'y')
		{
			gameIsOver = false;
			guessWords.clear();
			randWord = GetRandomWord(inWords, lines, linesNum);
		}
		else if (toupper(input[0]) == 'n')
		{
			gameIsActive = false;
		}
	}
}

void CheckGameOver(GuessWord& tempGuessWord, string& targetWord)
{
	if (stringToUpper(tempGuessWord.word) == stringToUpper(targetWord))
	{
		cout
			<< FOREGROUND(ForegroundColor::BrightGreen, "Congratulations you guessed correctly, the word was: ")
			<< FOREGROUND(ForegroundColor::BrightGreen, targetWord) << "\n";
		gameIsOver = true;
	}
	else if (guessWords.size() == guessLimit)
	{
		cout
			<< FOREGROUND(ForegroundColor::BrightYellow, "GAME OVER, the correct word was: ")
			<< FOREGROUND(ForegroundColor::BrightYellow, targetWord) << "\n";
		gameIsOver = true;
	}
}

void PrintGameState(vector<GuessWord>& guessWords)
{
	cout << "WORDLE\n";
	for (int i = 0; i < guessLimit; i++)
	{
		if (guessWords.size() > 0 && guessWords.size() > i)
		{
			GuessWord& current = guessWords[i];
			for (int g = 0; g < letterLimit; g++)
			{
				cout << BACKGROUND(current.letterColors[g], current.word[g]);
			}
		}
		else
		{
			for (int g = 0; g < letterLimit; g++)
			{
				cout << "?";
			}
		}
		cout << "\n";
	}
}

void AddGuessWordToCollection(GuessWord& tempGuessWord, string& input, BackgroundColor  backColor[5], vector<GuessWord>& guessWords)
{
	tempGuessWord.word = input;

	for (int i = 0; i < letterLimit; i++)
	{
		tempGuessWord.letterColors[i] = backColor[i];
	}
	guessWords.push_back(tempGuessWord);
}

void ColorMatchingLetters(BackgroundColor  backColor[5], string& input, string& targetWord)
{
	for (int i = 0; i < letterLimit; i++)
	{
		backColor[i] = BackgroundColor::None;
		auto inChar = toupper(input[i]);
		if (inChar == toupper(targetWord[i]))
		{
			backColor[i] = BackgroundColor::Green;
		}
		else
		{
			for (int g = 0; g < letterLimit; g++)
			{
				if (inChar == toupper(targetWord[g]))
				{
					backColor[i] = BackgroundColor::Yellow;
				}
			}
		}
	}
}

bool IsValidInput(string& input, HashSet* lines)
{

	if (input.size() != letterLimit)
	{
		system("CLS");
		cout << FOREGROUND(ForegroundColor::BrightYellow, "Your input is not a five letter word! \n");
		return false;
	}

	if (!IsValidWord(lines, input))
	{
		system("CLS");
		cout << FOREGROUND(ForegroundColor::BrightYellow, "Your input is not a valid word! \n");
		return false;
	}

	return true;
}

