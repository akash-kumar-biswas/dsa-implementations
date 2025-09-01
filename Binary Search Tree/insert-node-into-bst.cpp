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

TreeNode* insert_node(TreeNode* root, int data){ 
    if(!root)
        return new TreeNode(data);   // if root is empty

    if(root->val < data){
        root->right = insert_node(root->right, data);
    }
    else{
        root->left = insert_node(root->left, data);
    }
    return root;
}

int main(){
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    cout << "Before inserting (inorder): ";
    inorder(root);

    root = insert_node(root,1);   // if root is empty , then if we don't reassign root, we have incorrect result
    cout << "\nAfter inserting value 1 (inorder): ";
    inorder(root);
    cout << "\n" << root->left->left->left->val;

    root = insert_node(root,9);
    cout << "\nAfter inserting value 9 (inorder): ";
    inorder(root);
    cout << "\n" << root->right->right->val;
    return 0;
}