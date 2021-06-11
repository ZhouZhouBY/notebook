#pragma once
#include "二叉树.h"
#include <vector>

using namespace Tree;

namespace PathSum {
	void run();

	void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& path, int target);
}