#include<bits/stdc++.h>
using namespace std;

// tree nodes

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// gloabl variables used in the subsequent code

vector<int> preorder;
int pre_index;
bool error_flag;


// helper function too delete the entire tree

void deleteTree(Node* root){
    if(root != NULL){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    return;
}

// input parsing

vector<int> splitInput(string line){
    vector<int> arr;

    stringstream ss(line);

    int value;

    while(ss >> value){
        arr.push_back(value);
    }

    return arr;
}

// this helper finds the root position in the inorder traversal array

int findRootPosition(vector<int> inorder , int start, int end , int root_data){
    for(int i=start;i<=end;i++){
        if(inorder[i] == root_data){
            return i;
        }
    }

    return -1; //root not founf
}


// level order traversal of tree

void levelOrder(Node* root){
    if(root == NULL){
        return;
    }


    queue<Node*> q;
    q.push(root);
    vector<string> result;

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();


        if(curr == NULL){
            result.push_back("NULL");
        }else{


            result.push_back(to_string(curr->data));

            q.push(curr->left);
            q.push(curr->right);
        }


    }

    while(!result.empty() && result.back() == "NULL"){
        result.pop_back();
    }

    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }

    cout << endl;
}


// function to recursively build the tree


Node* buildTree(vector<int> inorder , int start , int end ,int n){
    if(start > end){
        return NULL;
    }

    if(pre_index >= n){
        error_flag = true;
        return NULL;
    }

    if(error_flag){
        return NULL;
    }

    int root_data = preorder[pre_index];
    pre_index++;

    int root_position = findRootPosition(inorder,start,end,root_data);

    if(root_position == -1){
        error_flag = true;
        return NULL;
    }

    Node* root = new Node;

    root->data = root_data;
    root->left = buildTree(inorder,start,root_position-1,n);
    root->right = buildTree(inorder,root_position+1,end,n);


    return root;
}


// main function for handliung inputs appropriately
int main(){

    int k;
    cin >> k;
    cin.ignore();


    while(k--){


        string line;
        vector<int> inorder;

        getline(cin,line);
        inorder = splitInput(line);

        int n = inorder.size();
        getline(cin,line);


        preorder = splitInput(line);
        int m = preorder.size() ;


        if(n != m){
            cout << "ERROR" << endl;
            continue;
        }

    pre_index = 0;
    error_flag = false;

    Node* root = buildTree(inorder,0,n-1,n);

    if(error_flag || root == NULL || pre_index != n){
        cout << "ERROR" << endl;

        deleteTree(root);

    }else{
        levelOrder(root);
        deleteTree(root);
    }


    preorder.clear();

    }


    return 0;
}