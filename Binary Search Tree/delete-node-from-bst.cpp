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


TreeNode* findInorderSuccess(TreeNode* root){
    if(!root->left)
        return root;
    return findInorderSuccess(root->left);
}

void delete_node(TreeNode* &root, int data){ 
    if(!root)
        return;

    if(root->val == data){
        if(!root->left && !root->right){   // Case 1:  If it is a leaf node
            delete root;
            root = nullptr;
        }
        else if(!root->left || !root->right){   // Case 2: If it is non-leaf node and has 1-child
            TreeNode *child = (root->left)? root->left: root->right;
            delete root;
            root = child;
        }
        else{
            TreeNode* successor = findInorderSuccess(root->right);   // Case 3: If it is non-leaf node and has 2-child
            root->val = successor->val;
            delete_node(root->right, successor->val);
        }
        return;
    }
    delete_node(root->left, data);
    delete_node(root->right, data);
}

int main(){
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    cout << "Before deleting (inorder): ";
    inorder(root);

    delete_node(root,3);  
    cout << "\nAfter deleteing value 3 (inorder): ";
    inorder(root);
    return 0;
}