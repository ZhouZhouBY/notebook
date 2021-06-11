#include "二叉树的右视图.h"

using namespace LayerShow;

void TreeRightView::run()
{
	Tree::TreeNode* root =Tree::init();
	vector<vector<int>> vec;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();
		vector<int> tmp;
		while (size--) {
			TreeNode* cur = que.front();
			que.pop();
			tmp.push_back(cur->val);
			if (cur->left) {
				que.push(cur->left);
			}
			if (cur->right) {
				que.push(cur->right);
			}
		}
		vec.push_back(tmp);
	}
	for (auto v : vec) {
		cout << v.back() << endl;
	}
}
