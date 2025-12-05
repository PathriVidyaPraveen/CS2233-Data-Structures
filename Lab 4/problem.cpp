#include<bits/stdc++.h>
using namespace std;

// node definition for the tree

typedef struct node
{
int data;
struct node *left;
struct node *right;
} node;


// helper function to create a node with given inetger data
node* createNode(int key){
    node* newnode = (node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// helper function to insert a node as the left child

node* insertLeft(node* root , int key){
    node* newnode = createNode(key);
    if(root == NULL){
        root = newnode;
        return root;
    }
    root->left = newnode;
    return root;
}

// helper function to insert a node as the right child

node* insertRight(node* root , int key){
    node* newnode = createNode(key);
    if(root == NULL){
        root = newnode;
        return root;
    }
    root->right = newnode;
    return root;
}

// main logic of the function that constructs tree from pre order and inorder traversals
node* constructTree(int preOrderArray[] , int inOrderArray[] , int n){
    if(n == 0){
        return NULL;
    }
    if(n == 1){
        node* newnode = createNode(preOrderArray[0]);
        return newnode;
    }
    int root_val = preOrderArray[0];
    node* root = createNode(root_val);
    int m = 0;
    while(m<n){
        if(root_val == inOrderArray[m]){
            break;
        }

        m++;
    }
    int left_len = m;
    int right_len = n-m-1;
    if(m != 0 && n-m-1 != 0){
        int left_child_pre[m];
        int right_child_pre[n-m-1];
        int left_child_in[m];
        int right_child_in[n-m-1];
        for(int i=0;i<m;i++){
            left_child_pre[i] = preOrderArray[i+1];
            left_child_in[i] = inOrderArray[i];
        }
        for(int i=m+1;i<n;i++){
            right_child_pre[i-m-1] = preOrderArray[i];
            right_child_in[i-m-1] = inOrderArray[i];
        }
        root-> left = constructTree(left_child_pre,left_child_in,m);
        root-> right = constructTree(right_child_pre , right_child_in,n-m-1);
        // root = insertLeft(root,left_child->data);

        // root = insertRight(root,right_child->data);
    }else if(m != 0){
        int left_child_pre[m];

        int left_child_in[m];

        for(int i=0;i<m;i++){
            left_child_pre[i] = preOrderArray[i+1];
            left_child_in[i] = inOrderArray[i];
        }

        root->left = constructTree(left_child_pre,left_child_in,m);

        // root = insertLeft(root,left_child->data);


    }else{
        int right_child_pre[n-m-1];

        int right_child_in[n-m-1];

        for(int i=m+1;i<n;i++){
            right_child_pre[i-m-1] = preOrderArray[i];
            right_child_in[i-m-1] = inOrderArray[i];
        }

        root->right = constructTree(right_child_pre,right_child_in,n-m-1);

        // root = insertRight(root,right_child->data);

    }

    return root;

    
}




// function for writing the pre order traversal of a given tree

void preOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}

// function for writing in order traversal of a tree

void inOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);

}

// function for writing post order traversal of a tree

void postOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// main function

int main(){

    int k;
    cin >> k;
    // test cases
    while(k--){

        // main code

        int n;
        cin >> n;
        int preOrderArray[n];
        for(int i=0;i<n;i++){
            cin >> preOrderArray[i];
        }

        int inOrderArray[n];
        for(int i=0;i<n;i++){
            cin >> inOrderArray[i];
        }

        node* tree_constructed = constructTree(preOrderArray,inOrderArray,n);
        preOrderTraversal(tree_constructed);
        cout << endl;
        postOrderTraversal(tree_constructed);
        cout << endl;
        inOrderTraversal(tree_constructed);
        cout << endl;


    }

    // Asymptotic upper bound on the worst case running time is O(n^2)

    return 0;
}