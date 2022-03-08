#include <string>
#include "Color.h"
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
		for (int i = 0; i < 5; i++)
		{
			letterColors[i] = inColors[i];
		}
	}
	string word;
	BackgroundColor letterColors[5];

};