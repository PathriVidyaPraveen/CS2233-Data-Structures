#include<bits/stdc++.h>
using namespace std;

// node definition for BST

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;

} Node;

// helper to insert a value in BST and returns root

Node* insertBST(Node* root, int value){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;


    if(root == NULL){
        return newnode;
    }

    Node* curr = root;

    while(true){

        if(value < curr->data){

            if(curr->left == NULL){
                curr->left = newnode;
                break;
            }
            curr = curr->left;
        }else{
            if(curr->right == NULL){
                curr->right = newnode;
                break;
            }
            curr = curr->right;
        }


    }

    return root;

}

// helper function to find the least common ancestor of 2 nodes


Node* LCA(Node* root , int value1, int value2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == value1 || root->data == value2){
        return root;
    }

    Node* left_lca = LCA(root->left,value1,value2);
    Node* right_lca = LCA(root->right,value1,value2);

    if(left_lca != NULL && right_lca != NULL){
        return root;
    }else if(left_lca != NULL){
        return left_lca;
    }else if(right_lca != NULL){
        return right_lca;
    }else{
        return NULL;
    }
}


// find path from starting node to target end value (path stored in the argument vector)

void findPath(Node* start , int target,vector<int>& path){

    Node* curr = start;

    while(curr != NULL){
        path.push_back(curr->data);
        if(curr->data == target){
            return ;
        }
        if(target < curr->data){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }


    return;

}

/// main function for handling inputs appropriately

int main(){

    int n;
    cin >> n;


    Node* root = NULL;

    for(int i=0;i<n;i++){
        int val;
        cin >> val;
        root = insertBST(root,val);
    }


    int q;
    cin >> q;
    while(q--){

        int u,v,k;
        cin >> u >> v >> k;

        Node* lca = LCA(root,u,v);

        vector<int> path_from_lca_to_u;
        findPath(lca,u,path_from_lca_to_u);

        vector<int> path_from_lca_to_v;
        findPath(lca,v,path_from_lca_to_v);

        // path from u to v = path from u to LCA + path from LCA to v

        reverse(path_from_lca_to_u.begin(),path_from_lca_to_u.end());

        vector<int> full_path = path_from_lca_to_u;

        for(int i=1;i<path_from_lca_to_v.size();i++){
            full_path.push_back(path_from_lca_to_v[i]);
        }

        if(k >= 1 && k <= full_path.size()){
            cout << full_path[k-1] << endl;
        }else{
            cout << -1 << endl;
        }

    }



    return 0;
}