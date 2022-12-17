#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};


TreeNode* buildBST(TreeNode *root, int data){
    if(root == nullptr){
        return new TreeNode(data);
    }
    if(data < root->data){
        root->left = buildBST(root->left, data);
    }
    else{
        root->right = buildBST(root->right, data);
    }
    return root;
}


void insertIntoBST(TreeNode *&root){
    int data;
    cout << "Enter Data" <<endl;
    cin >> data;

    while(data != -1){
        root = buildBST(root, data);
        cin >> data;
    }
}

void preorder(TreeNode *root){
    if(root == nullptr) return;
    cout << root->data <<' ';
    preorder(root->left);
    preorder(root->right);
}

void levelorder(TreeNode *root){
    if(root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode *curr = q.front();
                q.pop();
                cout << curr->data << " ";

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            cout <<endl;
    }
}

TreeNode* arrayToBST(TreeNode *&root, vector<int> &vec, int start, int end){
    if(start > end){
        return nullptr;
    }
    int mid = (end-start)/2 + start;
    root = new TreeNode(vec[mid]);
    root->left = arrayToBST(root->left, vec, start, mid-1);
    root->right = arrayToBST(root->right, vec, mid+1, end);
    return root;
}
TreeNode* floor(TreeNode *root, int key){
    if(!root) return root;

    TreeNode *ptr = root;
    TreeNode *ans = nullptr;
    while(ptr){
        if(ptr->data == key) return ptr;
        else if(ptr->data > key) ptr = ptr->left;
        else {
            if(ans == nullptr){
                ans = ptr;
            }else {
                if(ans->data < ptr->data) ans = ptr;
            }
            ptr = ptr->right;
        }
    }
    return ans;
}
TreeNode* ceil(TreeNode* root, int key){
    if(!root) return nullptr;
    TreeNode* ptr = root;
    TreeNode *ans = nullptr;
    while(ptr){
        if(ptr->data == key) return ptr;
        else if(ptr->data < key) ptr = ptr->right;
        else {
            ans = ptr;
            ptr = ptr ->left;
        }
    }
    return ans;
}

int main(){
    TreeNode *root = nullptr;
    vector<int> data = {1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20};
    arrayToBST(root, data, 0, 18);
    preorder(root);
    cout <<"\nLevelORder"<<endl;
    levelorder(root);
    TreeNode *c = floor(root, 7);
    int res = (c == nullptr)? -9 : c->data;
    cout << endl << "Ceil of 6 is : " << res;
}