#include<iostream>
#include<stack>
#include "MyList.h"
using namespace std;
using namespace MYLIST;

namespace reverseList {
	MyList* init();
	/*void show(MyList*);*/
	MyList* reverse1(MyList*);
	MyList* reverse2(MyList*);
	MyList* reverse2helper(MyList*, MyList*);
	MyList* reverse3(MyList*);
	void Run();
}