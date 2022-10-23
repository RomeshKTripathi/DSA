#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int val){
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
};


/**
 * @brief Builds Binary tree 
 * 
 * 
 * @param root Empty pointer to root node 
 * @return TreeNode* returns the root node of the tree
 */
TreeNode* buildTree(TreeNode *root){
    int data;
    cout << "Enter Data " <<endl;
    cin >> data;
    if(data == -1) return nullptr;
    root = new TreeNode(data);

    cout << "Enter Data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}


/**
 * @brief Traverse Tree in left-subtree, node, right-subtree faishon
 * 
 * @param root root of the tree to traverse
 */
void inorder(TreeNode *root){
    if(root == nullptr) return ;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

/**
 * @brief Traverse Tree in node, left-subtree, right-subtree faishon
 * 
 * @param root root of the tree to traverse
 */
void preorder(TreeNode *root){
    if(root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

/**
 * @brief Traverse Tree in left-subtree, riht-subtree, node faishon
 *
 * @param root root of the tree to traverse 
 */
void postorder(TreeNode *root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root ->val << " ";
}


/**
 * @brief Traverse tree in Level order faishon
 * 
 * @param root root of the tree to traverse
 */
void levelorder(TreeNode *root){
    if(root == nullptr)return;
    queue<TreeNode *> q;
    q.push(root);
    while(! q.empty()){
        int size = q.size();
        for(int i = 0;i<size; i++){
            TreeNode *curr = q.front();
            q.pop();
            cout << curr->val <<' ';
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        cout << endl;
    }

}



/**
 * @brief Returns maximum width of the tree
 * 
 * @param root root node of the tree
 * @return int 
 */
int width(TreeNode *root){
    if(root == nullptr) return 0;
    queue<TreeNode *> q;
    int width = 0;
    q.push(root);
    while(! q.empty()){
        int size = q.size();
        width = max(width, size);
        for(int i = 0;i<size; i++){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    return width;
}


/**
 * @brief return height of the tree
 * 
 * @param root root node of the tree
 * @return int 
 */
int height(TreeNode *root){
    if(root == nullptr)return 0;
    return max(height(root->left), height(root->right)) + 1;
}



int isBalanced(TreeNode *root){
    if(!root ) return 0;
    int lh = isBalanced(root->left);
    int rh = isBalanced(root->right);
    if(lh == -1 or rh == -1 or abs(lh-rh) > 1) return -1;
    return max(lh, rh) + 1;
}



int main(){
    TreeNode *root;
    root = buildTree(root);
    cout << "\nLevelorder\n";
    levelorder(root);
    cout << "Inorder \n";
    inorder(root);
    cout << "\nPreorder \n";
    preorder(root);
    cout << "\nPostorder\n";
    postorder(root);

    cout << "\nWidth of the tree : \n";
    cout << width(root);
    cout << "\nHeight of tree : \n" << height(root);
    cout << "\nIs Balanced : " << ((isBalanced(root) == -1)?"NO":"YES") <<endl;
}

//1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 