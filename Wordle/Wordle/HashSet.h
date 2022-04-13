#pragma once
#include <string>
using namespace std;

#define Capacity 50000000 
#define DefaultWordCount 8597

struct HashItem 
{
	string key;
};

struct HashSet 
{
	HashItem** items;
	int size;
	int count;
	int* indecies;
	
public:
	// feedback: I'm curious about the reason for making these functions static...
	// See my comment in StringUtility.cpp. I've seen this style before, mostly from people coming from C# background :)
	static HashSet* CreateSet(int size);

	static string* Find(HashSet* hSet, string* key);

	static void Add(HashSet* hSet, string key);

private:
	static HashItem* CreateItem(string key);
	static unsigned long HashFunction(HashSet* hSet,string* str);

	static void FreeItem(HashItem* item);
	static void FreeHashSet(HashSet* table);
};