#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size, double threshold, int methode) 
{
    hashTable = new vector<int>(size);
    hashTable->assign(size, -1);
    this->collisionCount = 0;
    this->elements = 0;
    this->size = size;
}

HashTable::~HashTable()
{
    delete hashTable;
}

int get_next_prime(int x)
{
	x = x + 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x += 1;
	}
}

int get_last_prime(int x)
{
	x = x - 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x -= 1;
	}
}

// Berechnung des Hashwertes 
int HashTable::hashValue(int item) 
{
    int index = -1; //dummy initialization

    int i = 0;
    index = item % this->size;    // hi(x) = (h(x) + i * i) % N)
    while (hashTable->at(index) != -1) {        // Kollision erkannt, while solange durchführen, bis kollision beseitigt ist
        i++;                                    // inkrementiere i
        this->collisionCount++;                       // inkrementiere collisionCount
        index = (item + i * i) % this->size;    // Quadratisches Sondieren
    }
    return index;

	switch (m_sondierMethode)
	{
	case (1):
		// Lineares Sondieren
		
		break;
	case (2):
		// Quadr. Sondieren
		
		break;
	case (3):
		{
			// Doppeltes Hashing
			int R = get_last_prime(size);
			
		}
	default:
		break;
	}
	return 1;
}
	

void HashTable::rehashing()
{
	
}

int HashTable::insert(int item) 
{
    int index = hashValue(item);
    hashTable->at(index) = item;
    elements++;
    return index; //dummy return
}

bool HashTable::search(int item) {
    int index = -1;
    int i = 0;
    index = (item + i * i) % this->size;
    while (hashTable->at(index) != item) {
        if (hashTable->at(index) == item) {
            break;
        }
        i++;
        this->collisionCount++;
        if (this->getCollisionCount() == 5) {
            cout << "nichts Gefunden\n";
            return false;
        }
    }
    if (hashTable->at(index) == item) {
        cout << "Item: " << item << " gefunden\n";
        return true;
    }
}

int HashTable::at(int i) 
{
	return hashTable->at(i);
}

int HashTable::getCollisionCount() 
{
	return this->collisionCount;
}

int HashTable::getSize() 
{
	return this->size;
}

int HashTable::getElements() 
{
	return this->elements;
}



