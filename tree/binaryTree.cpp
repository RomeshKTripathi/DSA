#include <iostream>
#include <queue>
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
    cout << "Enter left of " << root->data << endl;
    cin >> value;
    if (value != -1)
    {
        root->left = new TreeNode(value);
        createTree(root->left);
    }
    cout << "Enter Right of " << root->data << endl;
    cin >> value;
    if (value != -1)
    {
        root->right = new TreeNode(value);
        createTree(root->right);
    }
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
void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}
void postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << endl;
}

int heightOfTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

// Level order Traversal
// 1 -> push in queue
// 2 3 -> child of 1 i.e. in queue already
// 4 5 6 7 -> children of 2 and 3

void levelorderTraversal(TreeNode *root)
{
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    { // if queue is non empty than we can traverse subtrees of those nodes, i.e. in queue
        TreeNode *temp = que.front();
        que.pop();
        cout << temp->data << endl;
        if (temp->left != nullptr)
            que.push(temp->left);
        if (temp->right != nullptr)
            que.push(temp->right);
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    createTree(root);
    cout << "\nLevelorder Traversla\n";
    levelorderTraversal(root);

    cout << "\nHeight of Tree \n";
    cout << heightOfTree(root);
    // 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
}
/*
        1
    2       3
  4    5  6   7
  */

// 1 2 -1 -1 3 -1 -1