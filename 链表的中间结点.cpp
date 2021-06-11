#include "链表的中间结点.h"

using namespace MYLIST;

void MIDDLENODE::run()
{
	MyList* root = init();
	show(root);
	MyList* fast = root;
	MyList* slow = root;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	show(slow);
}
