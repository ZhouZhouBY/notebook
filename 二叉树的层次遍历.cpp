#include "二叉树的层次遍历.h"

void LayerShow::show(TreeNode* root)
{
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();
		while (size--) {
			TreeNode* cur = que.front();
			cout << cur->val << " ";
			que.pop();
			if (cur->left != nullptr) {
				que.push(cur->left);
			}
			if (cur->right != nullptr) {
				que.push(cur->right);
			}
		}
		cout << endl;
	}
}

void LayerShow::run()
{
	TreeNode* root = init();
	show(root);
}
