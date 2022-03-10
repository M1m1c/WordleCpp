#include "HashSet.h"


HashSet* HashSet::CreateSet(int size)
{
	HashSet* set = (HashSet*)malloc(sizeof(HashSet));
	set = new (set) HashSet();
	set->size = size;
	set->count = 0;
	set->items = (HashItem**)calloc(set->size, sizeof(HashItem*));
	for (int i = 0; i < set->size; i++)
	{
		set->items[i] = NULL;
	}

	return set;
}

void HashSet::Add(HashSet* table, string* key)
{
	HashItem* item = CreateItem(key);

	int index = HashFunction(key);

	HashItem* current = table->items[index];
	if (current == NULL) {
		if (table->count == table->size) {
			printf("Insert Error: Hash Table is full\n");
			FreeItem(item);
			return;
		}
		table->items[index] = item;
		table->count++;
	}
	else 
	{
		//TODO Handle collisions
	}
}



string* HashSet::Find(HashSet* table, string key) {
	
	string* retval = NULL;

	int index = HashFunction(&key);
	HashItem* item = table->items[index];

	if (item != NULL) {
		if (*item->key == key)
		{
			retval = item->key;
		}
	}
	return retval;
}

HashItem* HashSet::CreateItem(string* key)
{
	HashItem* item = (HashItem*)malloc(sizeof(HashItem));
	item = new (item) HashItem();
	item->key = key;
	
	return item;
}


unsigned long HashSet::HashFunction(string* str)
{
	unsigned long retval = hash<string>{}(*str);
	return retval % CAPACITY;
}

void HashSet::FreeItem(HashItem* item)
{
	free(item->key);
	free(item);
}

void HashSet::FreeTable(HashSet* table)
{
	for (int i = 0; i < table->size; i++) {
		HashItem* item = table->items[i];
		if (item == NULL) { continue; }
		FreeItem(item);
	}

	free(table->items);
	free(table);
}