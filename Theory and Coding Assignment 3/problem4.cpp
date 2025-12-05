#include <bits/stdc++.h>
using namespace std;


typedef struct node {
    int data;
    int height; /* stores the height of the current node */
    struct node* left;
    struct node* right;

} Node;

int single_rotations = 0;
int double_rotations = 0;

// helper function to compute height of tree rooted at root

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int balanceFactor(Node* root){
    if(root == NULL){
        return 0;
    }
    int balance_factor = height(root->left) - height(root->right);
    return balance_factor;
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    //rotate now

    x->right = y;
    y->left = T2;

    // update heights

    y->height = 1 + max(height(y->left) , height(y->right));
    x->height = 1 + max(height(x->left) , height(x->right));
    single_rotations++;
    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    //rotate now
    y->left = x;
    x->right = T2;
    
    // update heights

        x->height = 1 + max(height(x->left) , height(x->right));
    y->height = 1 + max(height(y->left) , height(y->right));

    single_rotations++;

    return y;
}


Node* rightRotateNoIncrement(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    //rotate now

    x->right = y;
    y->left = T2;

    // update heights

    y->height = 1 + max(height(y->left) , height(y->right));
    x->height = 1 + max(height(x->left) , height(x->right));
    // single_rotations++;
    return x;
}

Node* leftRotateNoIncrement(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    //rotate now
    y->left = x;
    x->right = T2;
    
    // update heights

        x->height = 1 + max(height(x->left) , height(x->right));
    y->height = 1 + max(height(y->left) , height(y->right));

    //single_rotations++;

    return y;
}

// search function returns pointer to node if found else NULL

Node* searchNode(Node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(key == root->data){
        return root;
    }else if(key < root->data){
        return searchNode(root->left,key);
    }else{
        return searchNode(root->right,key);
    }


    return NULL;


    
}


Node* minimumValueNode(Node* root){
    Node* curr = root;
    while(curr != NULL && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}


// function to insert a node in the AVL tree

Node* insertNode(Node* root, int key){
    if(root == NULL){
        
        Node* newnode = (Node*)malloc(sizeof(struct node));
        newnode->data = key;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->height = 1;
        return newnode;
    }

    if(key < root->data){
        root->left = insertNode(root->left,key);
    }else if(key > root->data){
        root->right = insertNode(root->right ,key);

    }else{
        // duplicate found so no insertion
        
        return root;
    }


    root->height = 1 + max(height(root->left),height(root->right));


    int balance_factor = balanceFactor(root);

    // left left

    if(balance_factor > 1 && key < root->left->data){
        
        return rightRotate(root);
    }

    // right right

    if(balance_factor < -1 && key > root->right->data){
        
        return leftRotate(root);
    }

    // left right

    if(balance_factor > 1 && key > root->left->data){
        double_rotations++;
        
        root->left = leftRotateNoIncrement(root->left);
        return rightRotateNoIncrement(root);
    }


    // right left

    if(balance_factor < -1 && key < root->right->data){
        double_rotations++;
       
        root->right = rightRotateNoIncrement(root->right);
        return leftRotateNoIncrement(root);
    }




    return root;

}

// function to delete node from the AVL tree


Node* deleteNode(Node* root, int key){
    if(root == NULL){
        
        return root;
    }

    if(key < root->data){
        root->left = deleteNode(root->left,key);
    }else if(key > root->data){
        root->right = deleteNode(root->right,key);
    }else{

        // node found
        

        // node with only 1 child or no child

        if(!root->left || !root->right){
            Node* temp = NULL;
            if(root->left != NULL){
                temp = root->left;
            }else{
                temp = root->right;
            }

            if(temp == NULL){
                // no child
                free(root);
                root = NULL;
            }else{
                // 1 child
                Node* toDelete = root;
root = temp;
free(toDelete);

                
            }


            
        }else{
            // for node with 2 childen get inorder successor

            Node* temp = minimumValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
           
        }





    }

    if(root == NULL){
        return root;
    }


    root->height = 1 + max(height(root->left),height(root->right));

    // now balance the node
    int balance_factor = balanceFactor(root);

    // left left

    if(balance_factor > 1 && balanceFactor(root->left) >= 0){
        
        return rightRotate(root);
    }

    // right right

    if(balance_factor < -1 && balanceFactor(root->right) <= 0){
        
        return leftRotate(root);
    }

    // left right

    if(balance_factor > 1 && balanceFactor(root->left) < 0){
        double_rotations++;
        root->left = leftRotateNoIncrement(root->left);
        return rightRotateNoIncrement(root);
    }

    //right left

    if(balance_factor < -1 && balanceFactor(root->right) >0){
        double_rotations++;
        root->right = rightRotateNoIncrement(root->right);
        return leftRotateNoIncrement(root);
    }





    return root;
}

// level order traversal printing

void printLevelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){

            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        

        }

        cout << "\n";
    }
}

// inorder traversal function

void printInOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    printInOrderTraversal(root->left);
    cout << root->data << " ";
    printInOrderTraversal(root->right);
    return;
}



int main(){

    int n;
    cin >> n;

    Node* root = NULL;

    while(n--){
        char op;
        int key;
        cin >> op >> key;
        if(op == 'I'){

            Node* duplicate = searchNode(root,key);
            if(duplicate!=NULL){
                
            }else{
                root = insertNode(root,key);

            }

        }else if(op == 'D'){
            Node* found = searchNode(root,key);
            if(found == NULL){
                
            }else{
                root = deleteNode(root,key);
            }
        }
    }

    cout << "Inorder: ";
    printInOrderTraversal(root);
    cout << "\n";

    cout << "Single rotations: " << single_rotations << "\n";
    cout << "Double rotations: " << double_rotations << "\n";


    return 0;
}