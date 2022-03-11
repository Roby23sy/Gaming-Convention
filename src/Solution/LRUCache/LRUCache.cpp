#include "LRUCache.h"
#include <algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
	this->capacity = capacity;

	///lru.reserve(capacity);

}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
	for(int i = 0 ; i < requestsNo.size() ; i++)
		{			
			if(find(lru.begin() , lru.end() , requestsNo[i]) != lru.end())
				lru.erase(remove(lru.begin(), lru.end(), requestsNo[i]), lru.end());
				
			lru.insert(lru.begin() , requestsNo[i]);

			if(lru.size() > capacity)
				lru.resize(capacity);


		}

	return lru;
}

int LRUCache::getCapacity()
{
	return capacity;
}

int LRUCache::getSize()
{
	return size;
}

vector<int> LRUCache::getLRU()
{
	return lru;
}

int LRUCache::getLRUCapacity()
{
	return capacity;
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void LRUCache::setLRU(vector<int> aux)
{
	lru = aux;
}
