#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using std::ifstream;
#include "Wordle.h"
#include "Color.h"
#include "GuessWord.cpp"

int main()
{
	ifstream inWords;
	inWords.open("words.txt");
	if (!inWords) { return 1; }

	int linesNum = 0;
	vector<string> lines = GetWordsInFile(inWords, linesNum);

	auto targetWord = GetTargetWord(inWords, lines, linesNum);

	while (gameIsActive)
	{
		PrintGameState(guessWords);

		if (gameIsOver) 
		{			
			CheckPlayAgain(targetWord, inWords, lines, linesNum);
			system("CLS");
			continue;
		}

		cout << "please type a five letter word:\n";
		cin >> input;

		if (!IsValidInput(input, lines)) { continue; }

		GuessWord tempGuessWord;
		BackgroundColor backColor[5];

		ColorMatchingLetters(backColor, input, targetWord);

		AddGuessWordToCollection(tempGuessWord, input, backColor, guessWords);

		system("CLS");

		CheckGameOver(tempGuessWord, targetWord);
	}
}

void CheckPlayAgain(std::string& targetWord, std::ifstream& inWords, std::vector<std::string>& lines, int linesNum)
{
	cout << FOREGROUND(ForegroundColor::BrightYellow, "Would you like to play again y/n\n");
	cin >> input;
	if (input.size() > 0)
	{
		if (tolower(input[0]) == 'y')
		{
			gameIsOver = false;
			guessWords.clear();
			targetWord = GetTargetWord(inWords, lines, linesNum);
		}
		else if (tolower(input[0]) == 'n')
		{
			gameIsActive = false;
		}
	}
}

void CheckGameOver(GuessWord& tempGuessWord, std::string& targetWord)
{
	if (stringToLower(tempGuessWord.word) == stringToLower(targetWord))
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

vector<string> GetWordsInFile(ifstream& inWords, int& linesNum)
{
	vector<string> lines;
	string line;


	while (getline(inWords, line))
	{
		linesNum++;
		lines.push_back(line);
	}

	return lines;
}

string GetTargetWord(ifstream& inWords, vector<string>& lines, int linesNum)
{
	

	srand(time(0));
	int randomNumber = rand() % linesNum;

	return lines[randomNumber];
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

bool IsValidInput(string& input, vector<string>& lines)
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

void AddGuessWordToCollection(GuessWord& tempGuessWord, string& input, BackgroundColor  backColor[5], std::vector<GuessWord>& guessWords)
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
		auto inChar = tolower(input[i]);
		if (inChar == tolower(targetWord[i]))
		{
			backColor[i] = BackgroundColor::Green;
		}
		else
		{
			for (int g = 0; g < letterLimit; g++)
			{
				if (inChar == tolower(targetWord[g]))
				{
					backColor[i] = BackgroundColor::Yellow;
				}
			}
		}
	}
}

bool IsValidWord(vector<string>& lines, string& input)
{
	bool isValidWord = false;
	for (auto var : lines)
	{
		auto compLine = stringToLower(var);
		auto compInput = stringToLower(input);
		if (compInput == compLine) {
			isValidWord = true;
			break;
		}
	}
	return isValidWord;
}

string stringToLower(string input)
{
	string retval;

	for (auto var : input)
	{
		retval += tolower(var);
	}

	return retval;
}
