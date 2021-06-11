#pragma once
#include"二叉树.h"
#include"二叉树的层次遍历.h"
#include<iostream>

using namespace Tree;

namespace ISSYMMETICTREE {
	bool isSymmetric(TreeNode* root);
	bool isMirror(TreeNode* l, TreeNode* r);
	void run();
}