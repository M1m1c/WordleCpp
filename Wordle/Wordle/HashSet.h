#pragma once
#include <string>
using namespace std;

#define CAPACITY 500000 


struct HashItem 
{
	string* key;
};

struct HashSet 
{

	//TODO also save an expandable array of unsigned long indexes so that we can randomly get one
	HashItem** items;
	int size;
	int count;

public:
	static HashSet* CreateSet(int size);

	static string* Find(HashSet* table, string key);

	static void Add(HashSet* table, string* key);

private:
	static HashItem* CreateItem(string* key);
	static unsigned long HashFunction(string* str);

	static void FreeItem(HashItem* item);
	static void FreeTable(HashSet* table);
};







//void HandleConflict(HashSet* table, Hitem* item)
//{
//
//}