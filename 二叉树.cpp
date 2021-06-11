#include "二叉树.h"

Tree::TreeNode* Tree::init()
{
	/*TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);*/

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	return root;
}