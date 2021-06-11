#include "LRU.h"
using namespace LRU;

LRUCache::LRUCache(int capcity)
{
	m_cap = capcity;
	m_size = 0;
	head = new DoubleList();
	tail = new DoubleList();
	head->next = tail;
	tail->prev = head;
}

void LRUCache::insertToHead(DoubleList* node)
{
	head->next->prev = node;
	node->next = head->next;
	node->prev = head;
	head->next = node;
}

void LRUCache::removeTail()
{
	if (m_size <= 0) {
		return;
	}
	cout << "erase:" + tail->prev->val << endl;
	mp.erase(tail->prev->key);
	removeNode(tail->prev);
}

void LRUCache::removeNode(DoubleList* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
}

void LRUCache::moveToHead(DoubleList* node)
{
	removeNode(node);
	insertToHead(node);
}

void LRUCache::put(int key, int val)
{
	if (mp.count(key)) {
		mp[key]->val = val;
		moveToHead(mp[key]);
	}
	else {
		++m_size;
		if (m_size > m_cap) {
			--m_size;
			removeTail();
		}
		DoubleList* newNode = new DoubleList(key, val);
		insertToHead(newNode);
		mp[key] = newNode;
	}
}

int LRUCache::get(int key)
{
	if (!mp.count(key)) {
		return -1;
	}
	int val = mp[key]->val;
	moveToHead(mp[key]);
	return val;
}

void LRU::test() {
	LRUCache* cache = new LRUCache(2);
	cache->put(1, 1);
	cout << cache->get(1) << endl;
	cout << cache->get(2) << endl;
	cache->put(2, 2);
	cache->put(3, 3);
	cache->put(4, 4);
	cout << cache->get(1) << endl;
}
