#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

void inorder(TreeNode* root){
    if(!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    inorder(root);
    return 0;
}