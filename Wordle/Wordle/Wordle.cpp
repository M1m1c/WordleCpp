#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using std::ifstream;
#include "Wordle.h"

#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"

enum class ForegroundColor : int {
	Red = 31,
	Green = 32,
	Yellow = 33,
	BrightRed = 91,
	BrightGreen = 92,
	BrightYellow = 93
};

enum class BackgroundColor : int {
	Red = 41,
	Green = 42,
	Yellow = 43,
	BrightRed = 101,
	BrightGreen = 102,
	BrightYellow = 103
};

int main()
{
	ifstream inWords;
	inWords.open("words.txt");
	if (!inWords) { return 1; }
	cout << FOREGROUND(ForegroundColor::BrightRed, "Hello world!") << endl;
	cout << BACKGROUND(BackgroundColor::BrightRed, "Hello world!") << endl;

	/*while (getline(inWords, text))
	{
		cout << text << "\n";
	}*/

	int letterLimit = 5;
	string line;
	vector<string> lines;
	srand(time(0));

	int linesNum = 0;
	while (getline(inWords, line))
	{
		linesNum++;
		lines.push_back(line);
	}

	int random_number = rand() % linesNum;
	//cout << lines[random_number] << "\n";

	bool gameIsActive = true;
	while (gameIsActive)
	{
		//TODO write out guess and color letters
		cout << "WORDLE\n";
		for (int i = 0; i < 6; i++)
		{
			for (int g = 0; g < 5; g++)
			{
				cout << "?";
			}
			cout << "\n";
		}
		cout << "please type a five letter word:\n";
		string input;
		cin >> input;
		if (input.size() != letterLimit)
		{
			system("CLS");
			cout << FOREGROUND(ForegroundColor::BrightYellow,"Your input is not a five letter word! \n");
			continue;
		}

		if (!IsValidWord(lines, input))
		{
			system("CLS");
			cout << FOREGROUND(ForegroundColor::BrightYellow, "Your input is not a valid word! \n");
			continue;
		}
		
		//system("CLS");
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
