#include<iostream>
#include<map>
using namespace std;

namespace LRU {
	struct DoubleList {
		int key;
		int val;
		DoubleList* prev;
		DoubleList* next;
		DoubleList() :key(0), val(0), prev(nullptr), next(nullptr) {};
		DoubleList(int k, int v) :key(k), val(v), prev(nullptr), next(nullptr) {};
	};
	class LRUCache {
	private:
		map<int, DoubleList*> mp;
		DoubleList* head;
		DoubleList* tail;
		int m_size;
		int m_cap;
	public:
		LRUCache(int capcity);
		void insertToHead(DoubleList* node);
		void removeTail();
		void removeNode(DoubleList* node);
		void moveToHead(DoubleList* node);
		void put(int key, int val);
		int get(int key);
	};

	void test();
}