#include "tree.h"

TreeNode* traversal (vector<int>& inorder, vector<int>& postorder)
{
    if (postorder.size() == 0) return nullptr;
    int root_value = postorder[postorder.size() - 1];
    TreeNode *root = new TreeNode(root_value);

    if (postorder.size() == 1) return root;
    int delimiter_index = 0;
    for ( delimiter_index = 0; delimiter_index < inorder.size(); delimiter_index++)
    {
        if (root_value == inorder[delimiter_index]) break;
    }

    vector<int> left_inorder(inorder.begin(), inorder.begin()+delimiter_index);
    vector<int> right_inorder(inorder.begin()+delimiter_index+1, inorder.end());

    vector<int> left_postorder(postorder.begin(), postorder.begin()+delimiter_index);
    vector<int> right_postorder(postorder.begin()+delimiter_index, postorder.begin()+postorder.size()-1);

    root->left = traversal(left_inorder,left_postorder);
    root->right = traversal(right_inorder, right_postorder);
    return root;
}

int main()
{
    vector<int> inorder{9,3,15,20,7};
    vector<int> postorder{9,15,7,20,3};
    TreeNode* root = traversal(inorder, postorder);
    return 0;
}