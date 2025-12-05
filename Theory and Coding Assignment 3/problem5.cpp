#include<bits/stdc++.h>
using namespace std;

#define RED 0
#define BLACK 1

typedef struct Node{
    int key;
    bool color;
    Node* left;
    Node* right;
    Node* parent;


    Node(int k) : key(k),color(RED),left(NULL),right(NULL),parent(NULL){

    }

}Node;

void RB_ENUMERATE(Node* x,int a,int b){
    if(x==NULL){
        return;
    }

    if(x->key >= a && x->left != NULL){
        RB_ENUMERATE(x->left,a,b);
    }

        if(x->key >=a && x->key <=b){
        cout << x->key << " ";
    }

    if(x->key<=b && x->right !=NULL){
        RB_ENUMERATE(x->right,a,b);
    }

    return;
}

int main(){
    return 0;
}