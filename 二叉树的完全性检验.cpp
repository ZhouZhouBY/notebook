#include "二叉树的完全性检验.h"


void ISCOMPLETETREE::run()
{
	TreeNode* root = init();
	// show(root);
	queue<TreeNode*> que;
	que.push(root);
	bool flag = false;
	while (!que.empty()) {
		TreeNode* tmp = que.front();
		que.pop();
		if (tmp == nullptr) {
			flag = true;
			continue;
		}
		if (flag) {
			cout << false << endl;
			return;
		}
		que.push(tmp->left);
		que.push(tmp->right);
	}
	cout << true << endl;
}
