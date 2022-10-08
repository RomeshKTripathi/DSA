#include <iostream>
#include <algorithm>
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


int sizeOf(TreeNode *root){
    if(root == 0)return 0;
    return sizeOf(root->left) + sizeOf(root->right) + 1;
}


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


void printKthLevelNodes(TreeNode *root, int k, int level = 1)
{
    if(root == nullptr)
    {
        return;
    }
    if(level == k)
    {
        cout << root->data << endl;
        return ;
    }
    printKthLevelNodes(root->left, k, level+1);
    printKthLevelNodes(root->right, k, level+1);
}
// Level order Traversal
// 1 -> push in queue
// 2 3 -> child of 1 i.e. in queue already
// 4 5 6 7 -> children of 2 and 3
/**
 * @brief traverse the tree in level-order faishon 
 * this function prints the data on the output screen 
 * pass additional second boolean parameter 'true' if you need it in a 
 * dynamic array,
 * @param root 
 * @param isArray optional
 */
vector<vector<int>> levelorderTraversal(TreeNode *root, bool isArray = false)
{
    queue<TreeNode *> que;
    vector<vector<int>> ans;
    vector<int> vec;
    que.push(root);
    que.push(nullptr);
    while (!que.empty())
    { // if queue is non empty than we can traverse subtrees of those nodes, i.e. in queue
        TreeNode *temp = que.front();
        que.pop();
            if(!isArray){
                cout << temp->data << " ";
            }
            else{
                vec.push_back(temp->data);
            }
        if (temp->left != nullptr)
            que.push(temp->left);
        if (temp->right != nullptr)
            que.push(temp->right);
        if(que.front() == nullptr){
            que.pop();
            cout << endl;
            que.push(nullptr);
            if(isArray){
                ans.push_back(vec);
                vec.clear();
            }
        }
    }
}


int getMax(TreeNode *root){
    if(root == nullptr) return 0;
    int maximum = max(getMax(root->left), getMax(root->right));
    return max(maximum, root->data);
}


bool childSumProperty(TreeNode *root){
    if(root == nullptr)return true;
    if(root->left == nullptr and root->right == nullptr) return true;
    int sum = 0;
    if(root->left){
        sum += root->left->data;
    }
    if(root->right){
        sum += root->right->data;
    }
    return (sum == root->data and childSumProperty(root->left) and childSumProperty(root->right));


}

bool isBalanced(TreeNode *root){
    if(root == nullptr) return true;

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    return (abs(lh-rh)<=1 and isBalanced(root->right) and isBalanced(root->left));

}

int main()
{
    TreeNode *root = new TreeNode(20);
    createTree(root);
    // cout << "\nLevelorder Traversla\n";
    // levelorderTraversal(root,true);

    // cout << "\nHeight of Tree \n";
    // cout << heightOfTree(root) << endl;
    // cout << "3 nd level nodes" << endl;
    // printKthLevelNodes(root, 4);
    // cout << endl << "Size of The Tree :\n" << sizeOf(root);
    // cout << endl << "Maximum of the tree :\n" << getMax(root);

    cout << "Children sum property \n" << childSumProperty(root) << endl;
    cout << "Is Balanced Tree : " << ((isBalanced(root))?"Yes":"No");
    // 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
}
/*
        1
    2       3
  4    5  6   7
  89  10,11 12,13 14,15

2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 12 -1 -1 13 -1 -1 7 14 -1 -1 15 -1 -1
  
  */
//  child sum childSumProperty
// 8 3 -1 -1 5 -1 -1 12 -1 -1

// 1 2 -1 -1 3 -1 -1