/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

#include <bits/stdc++.h>
using namespace std;
/* Definition for a binary tree node. */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



// @lc code=start
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        if (root != nullptr) q.push(root);
        else return ret;
        while(!q.empty())
        {
            int len = q.size();
            vector<int> cur;
            for (int i = 0; i < len; i++)
            {
                TreeNode* cur_node = q.front();
                q.pop();
                cur.push_back(cur_node->val);
                if (cur_node->left != nullptr) q.push(cur_node->left);
                if (cur_node->right != nullptr) q.push(cur_node->right);
            }
            ret.push_back(cur);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
// @lc code=end

