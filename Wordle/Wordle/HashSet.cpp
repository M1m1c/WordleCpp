#include "HashSet.h"
#include <iostream>


HashSet* HashSet::CreateSet(int size)
{
	HashSet* hSet = (HashSet*)malloc(sizeof(HashSet));
	hSet = new (hSet) HashSet();
	hSet->size = size;
	hSet->count = 0;
	hSet->items = (HashItem**)calloc(hSet->size, sizeof(HashItem*));

	int* array{ new int[DefaultWordCount] {} };
	hSet->indecies = array;

	return hSet;
}

void HashSet::Add(HashSet* hSet, string key)
{
	HashItem* item = CreateItem(key);

	int index = HashFunction(hSet, &item->key);

	HashItem* current = hSet->items[index];
	if (current == NULL) 
	{
		auto tempCount = hSet->count;
		if (tempCount == hSet->size)
		{
			std::cout << "Insert Error: Hash Set is full\n";
			FreeItem(item);
			return;
		}
		hSet->items[index] = item;
		hSet->indecies[tempCount] = index;
		hSet->count++;
	}
	else
	{
		std::cout << "IndexCollision " << key << " with " << current->key << " at " << index;
	}
}



string* HashSet::Find(HashSet* hSet, string* key) {

	string* retval = NULL;

	int index = HashFunction(hSet, key);
	HashItem* item = hSet->items[index];

	if (item != NULL) {
		if (item->key == *key)
		{
			retval = &item->key;
		}
	}
	return retval;
}

HashItem* HashSet::CreateItem(string key)
{
	HashItem* item = (HashItem*)malloc(sizeof(HashItem));
	item = new (item) HashItem();
	item->key = key;

	return item;
}


unsigned long HashSet::HashFunction(HashSet* hSet, string* str)
{
	hash<string> hashFunc;
	unsigned long retval = (unsigned long)abs((int)hashFunc(*str) % Capacity);
	return  retval;
}



void HashSet::FreeItem(HashItem* item)
{
	free(&item->key);
	free(item);
}

void HashSet::FreeHashSet(HashSet* hSet)
{
	for (int i = 0; i < hSet->size; i++) {
		HashItem* item = hSet->items[i];
		if (item == NULL) { continue; }
		FreeItem(item);
	}

	free(hSet->items);
	free(hSet);
}