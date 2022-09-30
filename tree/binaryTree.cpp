#include <iostream>
using namespace std;

typedef struct TreeNode
{

    int data;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int data)
    {
        left = nullptr;
        right = nullptr;
    }

} TreeNode;

void createTree(TreeNode *root)
{
    if (root->data == -1)
        return;

    int data;
    TreeNode *node = nullptr;
    cout << "Enter data for left node : ";
    cin >> data;

    root->left = new TreeNode(data);
    cout << "Enter data for right node : ";
    cin >> data;

    root->right = new TreeNode(data);
    createTree(root->left);
    createTree(root->right);
}

void printTree(TreeNode *root)
{
    if (root->data == -1)
        return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    TreeNode *head = nullptr;
    head = new TreeNode(1);
    createTree(head);
    printTree(head);
}