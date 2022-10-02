#include <iostream>
using namespace std;

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
} TreeNode;

void createTree(TreeNode *root)
{
    if (root == nullptr)
        return;

    int value;
    cout << "Enter Left of " << root->data << " : ";
    cin >> value;

    if (value != -1)
    {
        TreeNode *temp = new TreeNode(value);
        root->left = temp;
    }

    cout << "Enter Right of " << root->data << " : ";
    cin >> value;

    if (value != -1)
    {
        TreeNode *temp = new TreeNode(value);
        root->right = temp;
    }
    createTree(root->left);
    createTree(root->right);
}

void preorderTraverse(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << endl;
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}
void inorder(TreeNode *root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}
void postorderTraversal(TreeNode *root){
    if(root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data <<endl;
}


int main()
{
    TreeNode *root = new TreeNode(1);
    createTree(root);
    preorderTraverse(root);
    cout << "\nPostorder Traversla\n";
    postorderTraversal(root);
    // 2 3 4 5 -1 -1 -1 -1 6 7 -1 -1 -1 -1
}
/*
        1
    2       3
  4    5  6   7
  */