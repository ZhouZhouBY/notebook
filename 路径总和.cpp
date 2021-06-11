#include "路径总和.h"

void PathSum::run()
{
	Tree::TreeNode* root = Tree::init();
	vector<vector<int>> paths;
	vector<int> path;
	int target;
	cin >> target;
	dfs(root, paths, path, target);
	for (auto pa : paths) {
		for (auto p : pa) {
			cout << p << " ";
		}
		cout << endl;
	}
}

void PathSum::dfs(TreeNode* root, vector<vector<int>>& paths, vector<int>& path, int target)
{
	if (!root) {
		return;
	}
	path.push_back(root->val);
	target -= root->val;
	if (!root->left && !root->right && target == 0) {
		paths.push_back(path);
	}
	dfs(root->left, paths, path, target);
	dfs(root->right, paths, path, target);
	target += root->val;
	path.pop_back();
}
