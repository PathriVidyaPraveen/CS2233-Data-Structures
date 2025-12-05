#include<bits/stdc++.h>
using namespace std;

typedef struct Node{

    int data;
    struct Node *left;
    struct Node *right;

} Node;


Node* createNode(int data){
    if(data == -1){
        return NULL;
    }
    Node* new_node = (Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;

}

void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

    return;
}

void inOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    
    inOrderTraversal(root->right);

    return;
}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";

    return;
}


int main(){

    int n;
    cin >> n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    Node* nodes[n];
    for(int i=0;i<n;i++){
        if(a[i] == -1){
            nodes[i] = NULL;
            continue;
        }
        nodes[i] = createNode(a[i]);
    }

    Node* root = nodes[0];

    int slowptr = 0;
    int fastptr = 1;

    while(fastptr < n){
        // int slow_index = slowptr-1;
        // int fast_index = fastptr-1;

        if(nodes[slowptr] == NULL){
            slowptr++;
            continue;
        }

        // add left child

        nodes[slowptr]->left = nodes[fastptr];
        fastptr++;

        // add right child

        nodes[slowptr]->right = nodes[fastptr];
        fastptr++;

        // move to next root node in that level 

        slowptr++;

    }


    cout << "Pre Order Traversal: " << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "In Order Traversal: " << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "Post Order Traversal: " << endl;
    postOrderTraversal(root);
    cout << endl;


    return 0;
}

