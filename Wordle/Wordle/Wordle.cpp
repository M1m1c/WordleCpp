#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using std::ifstream;

int main()
{
	ifstream inWords;
	string text;
	inWords.open("words.txt");
	if (!inWords) { return 1; }
	while (getline(inWords, text))
	{
		cout << text << "\n";
	}
}