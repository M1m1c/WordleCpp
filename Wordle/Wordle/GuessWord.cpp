#include <string>
#include "ColorCombo.h"
using namespace std;

struct GuessWord
{
public:
	GuessWord(string inWord,ColorCobmo (& inColorCombos)[5]) 
	{
		word = inWord;
		for (int i = 0; i < 5; i++)
		{
			letterColors[i] = inColorCombos[i];
		}
	}
	string word;
	ColorCobmo letterColors[5];

};