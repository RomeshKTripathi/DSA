#include <iostream>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template<typename T>

TreeNode<T>* buildTree(TreeNode<T> *root){
    int input;
    cin >> input;
    if(input == -1) return nullptr;
    root = new TreeNode<T>(input);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

template<typename T>
void print_inorder(TreeNode<T> *root){
    if(root == nullptr) return;
    cout<< root->data <<' ';
    print_inorder(root->left);
    print_inorder(root->right);
}

int main(){
    TreeNode<int> *tree;
    tree = buildTree(tree);
    print_inorder(tree);
}