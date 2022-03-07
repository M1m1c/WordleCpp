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
	//cout << targetWord << "\n";

	//TODO make check for if won or lost
	//TODO make check if user wants to play another round
	while (gameIsActive)
	{
		PrintGameState(guessWords);

		cout << "please type a five letter word:\n";
		cin >> input;

		if (!IsValidInput(input, lines)) { continue; }

		GuessWord tempGuessWord;
		BackgroundColor backColor[5];

		ColorMatchingLetters(backColor, input, targetWord);

		AddGuessWordToCollection(tempGuessWord, input, backColor, guessWords);

		system("CLS");
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
	for (int i = 0; i < 6; i++)
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
			for (int g = 0; g < 5; g++)
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
		backColor[i] = (BackgroundColor)0;
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
