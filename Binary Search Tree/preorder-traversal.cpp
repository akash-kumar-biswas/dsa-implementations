#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

void preOrder(TreeNode* root){
    if(!root)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    preOrder(root);
    return 0;
}