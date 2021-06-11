#include "两数相加.h"
#include<iostream>
using namespace std;

std::vector<MyList*> ADDTWONUM::init()
{
	MyList* num1 = new MyList(2);
	num1->next = new MyList(4);
	num1->next->next = new MyList(3);
	MyList* num2 = new MyList(5);
	num2->next = new MyList(6);
	num2->next->next = new MyList(4);
	return { num1, num2 };
}

void ADDTWONUM::run()
{
	vector<MyList*> nums = init();
	MyList* n1 = nums[0];
	MyList* n2 = nums[1];
	int carry = 0;
	MyList* resHead = new MyList(-1);
	MyList* p = resHead;
	while (n1 || n2 || carry) {
		int curVal = (n1 ? n1->val : 0) +( n2 ? n2->val : 0) + carry;
		// cout << curVal << endl;
		carry = curVal / 10;
		MyList* cur = new MyList(curVal % 10);
		p->next = cur;
		p = cur;
		if (n1) {
			n1 = n1->next;
		}
		if (n2) {
			n2 = n2->next;
		}
	}
	show(resHead->next);
}