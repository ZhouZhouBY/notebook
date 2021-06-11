#include"翻转链表.h"
using namespace reverseList;

MyList* reverseList::init() {
	MyList* head = new MyList(0);
	MyList* p = head;
	for (int i = 1; i < 5; ++i) {
		MyList* cur = new MyList(i);
		p->next = cur;
		p = cur;
	}
	return head;
}
//void reverseList::show(MyList* head) {
//	MyList* p = head;
//	while (p) {
//		cout << p->val << " ";
//		p = p->next;
//	}
//	cout << endl;
//}
MyList* reverseList::reverse1(MyList* head) {
	stack<MyList*> stk;
	while (head) {
		stk.push(head);
		MyList* next = head->next;
		head->next = nullptr;
		head = next;
	}
	MyList* newHead = new MyList(0);
	MyList* p = newHead;
	while (!stk.empty()) {
		p->next = stk.top();
		stk.pop();
		p = p->next;
	}
	return newHead->next;
}
MyList* reverseList::reverse2helper(MyList* head, MyList* newHead) {
	if (head == nullptr) {
		return newHead;
	}
	MyList* next = head->next;
	head->next = newHead;
	MyList* cur = reverse2helper(next, head);
	return cur;
}
MyList* reverseList::reverse2(MyList* head) {
	return reverse2helper(head, nullptr);
}
MyList* reverseList::reverse3(MyList* head) {
	MyList* pre = nullptr;
	while (head) {
		MyList* next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}
void reverseList::Run() {
	MyList* head = init();
	show(head);
	// 栈
	head = reverse1(head);
	show(head);
	// 递归
	head = reverse2(head);
	show(head);
	// 非递归
	head = reverse3(head);
	show(head);
}

