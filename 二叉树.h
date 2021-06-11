#pragma once

#include<iostream>
#include<queue>
using namespace std;

namespace Tree {
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
	};

	TreeNode* init();

}