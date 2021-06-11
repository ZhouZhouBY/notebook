#include "k个一组翻转链表.h"
#include "翻转链表.h"
#include <iostream>
using namespace std;

MyList* reverseMyList(MyList* pre, MyList* start, MyList* end) {
	MyList* first = start;
	MyList* second = start->next;
	first->next = nullptr;
	while (second != end) {
		MyList* tmp = second->next;
		second->next = first;
		first = second;
		second = tmp;
	}
	start->next = end->next;
	second->next = first;
	pre->next = second;
	return start;
}


void REVERSELISTKGROUP::feidiguirun()
{
	MyList* head = MYLIST::init();
	show(head);
	int k;
	cin >> k;
	MyList* newHead = new MyList(-1);
	MyList* pre = newHead;
	newHead->next = head;
	int tag = k;
	MyList* p = head;
	MyList* start = nullptr;
	MyList* end = nullptr;
	while (p) {
		if (tag == k) {
			start = p;
		}
		else if (tag == 1) {
			end = p;
			p = reverseMyList(pre, start, end);
			pre = p;
			tag = k + 1;
		}
		p = p->next;
		--tag;
	}
	show(newHead->next);
}

void REVERSELISTKGROUP::diguirun()
{
	MyList* head = MYLIST::init();
	show(head);
	int k;
	cin >> k;
	MyList* newHead = reverseKGroup(head, k);
	show(newHead);
}

MYLIST::MyList* REVERSELISTKGROUP::reverseKGroup(MyList* head, int k)
{
	if (!head || !head->next) {
		return head;
	}
	MyList* tail = head;
	for (int i = 0; i < k; ++i) {
		if (!tail) {
			return head;
		}
		tail = tail->next;
	}
	MyList* cur = head, * pre = nullptr, * next = nullptr;
	while (cur != tail) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	head->next = reverseKGroup(tail, k);
	return pre;
}

