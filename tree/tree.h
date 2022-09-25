#ifndef TREE_H
#define TREE_H
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

/* 106. 从中序与后序遍历序列构造二叉树
中序遍历：{9,3,15,20,7}，
后序遍历：{9,15,7,20,3}
*/

TreeNode* travesal(vector<int> &inorder, vector<int>& postorder);
#endif
