#include <string>
#include "ColorCombo.h"
using namespace std;

struct GuessWord
{
public:
	GuessWord()
	{
		word = "";
	}
	GuessWord(string inWord, BackgroundColor inColors[5])
	{
		word = inWord;
		for (int i = 0; i < sizeof(inColors) / sizeof(*inColors); i++)
		{
			letterColors[i] = inColors[i];
		}
	}
	string word;
	BackgroundColor letterColors[5];

};