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


// Level order Traversal
// 1 -> push in queue
// 2 3 -> child of 1 i.e. in queue already
// 4 5 6 7 -> children of 2 and 3

// void levelorderTraversal(TreeNode *root){
//     queue<TreeNode*> que;
//     que.push(root);
//     que.push(nullptr);
//     while(!que.empty()){ // if queue is non empty than we can traverse subtrees of those nodes, i.e. in queue
//         TreeNode *temp = que.front();
//         que.pop();
//         cout << temp->data;
//         if(temp->left)
//             que.push(root->left);
//         if(temp->right)
//             que.push(root->right);
//         if(que.front() == nullptr){
//             que.pop();
//             cout << endl;
//             que.push(nullptr);
//         }
//     }

// }



int main()
{
    TreeNode *root = new TreeNode(1);
    createTree(root);
    preorderTraverse(root);
    cout << "\nPostorder Traversla\n";
    postorderTraversal(root);
    // levelorderTraversal(root);
    // 2 3 4 5 -1 -1 -1 -1 6 7 -1 -1 -1 -1
}
/*
        1
    2       3
  4    5  6   7
  */