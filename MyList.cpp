#include "MyList.h"
#include <iostream>
using namespace std;

MYLIST::MyList* MYLIST::init()
{
	MyList* root = new MyList(0);
	MyList* p = root;
	for (int i = 1; i <= 5; ++i) {
		p->next = new MyList(i);
		p = p->next;
	}
	return root->next;
}

void MYLIST::show(MyList* root)
{
	MyList* p = root;
	while (p) {
		std::cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

void MYLIST::test()
{
	MyList* root = init();
	show(root);
}
