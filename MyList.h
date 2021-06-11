#pragma once

namespace MYLIST {
	struct MyList {
		int val;
		MyList* next;
		MyList(int v) : val(v), next(nullptr) {};
	};

	MyList* init();
	void show(MyList* root);
	void test();
}