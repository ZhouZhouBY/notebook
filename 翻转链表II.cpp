#include "翻转链表II.h"
using namespace std;

void REVERSELISTII::run()
{
	MyList* head = init();
	show(head);
	int left, right;
	cin >> left >> right;
	MyList* pre = new MyList(-1);
	MyList* Head = pre;
	pre->next = head;
	MyList* p = head;
	MyList* reversePre =pre;
	MyList* reverseHead = head;
	MyList* reverseTail = head;
	// show(Head);
	for (int i = 1; i <= right; ++i) {
		if (i == left) {
			reversePre = pre;
			reverseHead = p;
		}
		if (i == right) {
			reverseTail = p;
			cout << reversePre->val << " " << reverseHead->val << " " << reverseTail->val << endl;
			reverseListII(reversePre, reverseHead, reverseTail);
		}
		pre = p;
		p = p->next;
	}
	show(Head->next);
}

void REVERSELISTII::reverseListII(MyList* pre, MyList* head, MyList* tail) {
	MyList* p = head;
	MyList*	p1 = p->next;
	MyList* next = nullptr;
	while (p != tail) {
		p->next = next;
		next = p;
		p = p1;
		p1 = p1->next;
	}
	p->next = next;
	pre->next = p;
	head->next = p1;
}

