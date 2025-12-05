#include<bits/stdc++.h>
using namespace std;

// node defintion for tree


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


// fucntion to build tree from level order traversal

Node* buildTree(vector<string> nodes){

    if(nodes.empty() || nodes[0] == "null"){
        return NULL;
    }

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = stoi(nodes[0]);
    newnode->left = NULL;
    newnode->right = NULL;

    Node* root = newnode;
    queue<Node*> q;
    q.push(root);


    int i=1;
    while(!q.empty() && i < nodes.size()){
        Node* curr = q.front();
        q.pop();

        if(i < nodes.size() && nodes[i] != "null"){
                newnode = (Node*)malloc(sizeof(Node));
    newnode->data = stoi(nodes[i]);
    newnode->left = NULL;
    newnode->right = NULL;
            curr->left = newnode;
            q.push(curr->left);
        }
        i++;
        if(i < nodes.size() && nodes[i] != "null"){
                            newnode = (Node*)malloc(sizeof(Node));
    newnode->data = stoi(nodes[i]);
    newnode->left = NULL;
    newnode->right = NULL;
            curr->right = newnode;
            
            q.push(curr->right);
        }
        i++;
    }

    return root;
    
}

// main logic for finding range sum of BST in the inclusive range [low,high]


int rangeSumBST(Node* root , int low , int high){
    if(root == NULL){
        return 0;
    }

    int sum = 0;
    if(root->data > low){
        sum += rangeSumBST(root->left,low,high);
    }

    if(root->data >= low && root->data <= high){
        sum += root->data;
    }

    if(root->data < high){
        sum += rangeSumBST(root->right,low,high);
    }

    return sum;
}


int main(){

    string line;
    getline(cin,line);
    string node_string;
    vector<string> nodes;
    stringstream ss(line);
    while(ss >> node_string){
        nodes.push_back(node_string);
    }

    Node* root = buildTree(nodes);
    int low , high;
    cin >> low >> high;
    int result = rangeSumBST(root,low,high);
    cout << result << endl;



    return 0;
}

