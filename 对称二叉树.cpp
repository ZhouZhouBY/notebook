#include "对称二叉树.h"

using namespace LayerShow;

bool ISSYMMETICTREE::isSymmetric(TreeNode* root)
{
	if (!root) {
		return true;
	}
	return isMirror(root->left, root->right);
}

bool ISSYMMETICTREE::isMirror(TreeNode* l, TreeNode* r)
{
	if (!l && !r) {
		return true;
	}
	if (!l || !r) {
		return false;
	}
	return (l->val == r->val) && isMirror(l->right, r->left) && isMirror(l->left, r->right);
}

void ISSYMMETICTREE::run()
{
	TreeNode* root = init();
	show(root);
	bool res = isSymmetric(root);
	cout << res << endl;
}
