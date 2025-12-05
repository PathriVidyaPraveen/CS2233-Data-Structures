#include<bits/stdc++.h>
using namespace std;

// MAX = max children , MIN = min keys
const int t = 3;
const int MIN = t-1;
const int MAX = 2*t-1;

// definition of node
typedef struct BTreeNode {
    int key[MAX];
    int count;
    BTreeNode *children[MAX+1];

    BTreeNode():count(0){
        for(int i=0;i<MAX+1;i++){
            children[i]= NULL;
        }
    }



} BTreeNode;

// helper function to check if node is leaf

// bool isLeaf(BTreeNode* node){
//     return node->children[0]==NULL;
// }

BTreeNode* root = NULL;


// search function returns the node to key if found or NULL if not found

BTreeNode* search(BTreeNode* root, int key){
    if(root==NULL){
        return NULL;
    }
    int i=0;
    while(i < root->count && key>root->key[i]){
        i++;
    }


    if(i<root->count && key==root->key[i]){
        return root;
    }
    if(root->children[0]==NULL){
        return NULL;
    }


    return search(root->children[i],key);


}

// splits a full child node

void splitChild(BTreeNode* parent, int i, BTreeNode* y){
    BTreeNode* x = new BTreeNode();

    x->count=MIN;
    for(int j=0;j<MIN;j++){
        x->key[j]=y->key[j+t];
    }
    if(y->children[0] != NULL){
        for(int j=0;j<t;j++){
            x->children[j]=y->children[j+t];
        }
    }
    y->count=MIN;
    for(int j=parent->count;j>i;j--){
        parent->children[j+1] = parent->children[j];
    }
    parent->children[i+1]=x;
    for(int j=parent->count-1;j>=i;j--){
        parent->key[j+1]=parent->key[j];
    }
    parent->key[i]=y->key[t-1];
    parent->count++;
}


// helper function to insertt key into non full node

void insertNonFullNode(BTreeNode* node,int x){
    int i=node->count-1;
    if(node->children[0]==NULL){
        while(i>=0&&x<node->key[i]){
            node->key[i+1]=node->key[i];
            i--;
        }
        node->key[i+1]=x;
        node->count++;
    }else{
        while(i>=0 &&x<node->key[i]){
            i--;
        }
        i++;
        if(node->children[i]->count==MAX){
            splitChild(node,i,node->children[i]);
            if(x>node->key[i]){
                i++;
            }
        }
        insertNonFullNode(node->children[i],x);
    }
}

// Function to insert a node 


void insert(int x){
    if(search(root,x) != NULL){
        cout << x << " already present. So no need to insert." << endl;
        return;
    }

    if(root == NULL){
        root = new BTreeNode();
        root->key[0]=x;
        root->count=1;
    }else{
        if(root->count==MAX){
            BTreeNode* s = new BTreeNode();
            s->children[0]=root;
            splitChild(s,0,root);
            int i=0;
            if(s->key[0]<x){
                i++;
            }
            insertNonFullNode(s->children[i],x);
            root=s;
        }else{
            insertNonFullNode(root,x);
        }
    }


    cout << x << " inserted" << endl;
}

// same insert function without messages

void insertWithoutMessage(int x){
    if(search(root,x) != NULL){
        //cout << x << " already present. So no need to insert." << endl;
        return;
    }

    if(root == NULL){
        root = new BTreeNode();
        root->key[0]=x;
        root->count=1;
    }else{
        if(root->count==MAX){
            BTreeNode* s = new BTreeNode();
            s->children[0]=root;
            splitChild(s,0,root);
            int i=0;
            if(s->key[0]<x){
                i++;
            }
            insertNonFullNode(s->children[i],x);
            root=s;
        }else{
            insertNonFullNode(root,x);
        }
    }


    //cout << x << " inserted" << endl;
}

// find index of 1st key >= x in the node

int findKey(BTreeNode* node,int x){
    int index=0;
    while(index < node->count && node->key[index] < x){
        index++;

    }


    return index;
}

// helper to find predecessor key

int findPredecessor(BTreeNode* node){
    while(node->children[0] !=NULL){
        node=node->children[node-> count];

    }

    return node->key[node->count-1];
}

// helper to find successor key

int findSuccessor(BTreeNode* node){
    while(node->children[0] !=NULL){
        node=node->children[0];
    }
    return node->key[0];
}

// helperr to merge children[index+1] to children[index]

void merge(BTreeNode* parent,int index){
    BTreeNode* child = parent->children[index];
    BTreeNode* sb = parent->children[index+1];
    child->key[child->count]=parent->key[index];
    child->count++;
    for(int i=0;i<sb->count;i++){
        child->key[child->count]=sb->key[i];
        child->count++;
    }
    if(child->children[0]!=NULL){
        for(int i=0;i<=sb->count;i++){
            child->children[i+t]=sb->children[i];
        }
    }


    for(int i=index+1;i<parent->count;i++){
        parent->key[i-1] = parent->key[i];
    }

    for(int i=index+2;i<=parent->count;i++){
        parent->children[i-1]= parent->children[i];
    }

    parent->count--;
    delete sb;
}

// helper to borrow key from left sibling

void borrowFromPrevious(BTreeNode* parent,int index){
    BTreeNode* child = parent->children[index];
    BTreeNode* sb = parent->children[index-1];
    for(int i=child->count-1;i>=0;i--){
        child->key[i+1]=child->key[i];
    }
    if(child->children[0]!=NULL){
        for(int i=child->count;i>=0;i--){
            child->children[i+1]=child->children[i];
        }
    }
    child->key[0]=parent->key[index-1];
    if(child->children[0]!=NULL){
        child->children[0]=sb->children[sb->count];
    }
    parent->key[index-1]= sb->key[sb->count-1];
    child->count++;
    sb->count--;

    
}

// helper to borrow key from right sibling

void borrowFromNext(BTreeNode* parent,int index){
    BTreeNode* child = parent->children[index];
    BTreeNode* sb = parent->children[index+1];

    child->key[child->count] = parent->key[index];

    // BTreeNode* child = parent->children[index];
    // BTreeNode* sb = parent->children[index-1];
    // for(int i=child->count-1;i>=0;i--){
    //     child->key[i+1]=child->key[i];
    // }
    // if(child->children[0]!=NULL){
    //     for(int i=child->count;i>=0;i--){
    //         child->children[i+1]=child->children[i];
    //     }
    // }
    // child->key[0]=parent->key[index-1];
    // if(child->children[0]!=NULL){
    //     child->children[0]=sb->children[sb->count];
    // }
    // parent->key[index-1]= sb->key[sb->count-1];
    // child->count++;
    // sb->count--;

    if(child->children[0]!=NULL){
        child->children[child->count+1] = sb->children[0];
    }
    parent->key[index] =sb->key[0];
    for(int i=1;i<sb->count;i++){
        sb->key[i-1]=sb->key[i];
    }

    if(sb->children[0]!=NULL){
        for(int i=1;i<=sb->count;i++){
            sb->children[i-1] = sb->children[i];
        }
    }

    child->count++;
    sb->count--;

    
}

// recursively delete key from b tree

void deleteInternal(BTreeNode* node,int x){
    int index = findKey(node,x);
    if(index < node->count && node->key[index]==x){
        if(node->children[0]==NULL){
            for(int i=index+1;i<node->count;i++){
                node->key[i-1]=node->key[i];
            }
            node->count--;
        }else{
            BTreeNode* left_child = node->children[index];
            BTreeNode* right_child = node->children[index+1];
            if(left_child->count>=t){
                int predecessor = findPredecessor(left_child);
                node->key[index] = predecessor;
                deleteInternal(left_child,predecessor);
            }else if(right_child->count>= t){
                int successor = findSuccessor(right_child);
                node->key[index] = successor;
                deleteInternal(right_child,successor);
            }else{
                merge(node,index);
                deleteInternal(left_child,x);
            }
        }
    }else{
        if(node->children[0]==NULL){
            return;
        }
        BTreeNode* child_to_descend = node->children[index];
        if(child_to_descend->count==MIN){
            BTreeNode* left_sb = (index>0) ? (node->children[index-1]): NULL;
            BTreeNode* right_sb = (index<node->count)?(node->children[index+1]):NULL;
            if(left_sb!=NULL && left_sb ->count >=t){
                borrowFromPrevious(node,index);
            }else if(right_sb != NULL && right_sb->count >= t){
                borrowFromNext(node,index);
            }else{
                if(right_sb !=NULL){
                    merge(node,index);
                }else{
                    merge(node,index-1);
                    child_to_descend = node->children[index-1];
                }
            }
        }



        deleteInternal(child_to_descend,x);
    }

    return;
}

// helper to print level order traversal

void levelOrderTraversal(){
    if(root==NULL){
        return;
    }

    queue<BTreeNode*> q;
    q.push(root);
    while(!q.empty()){

        int size = q.size();
        for(int i=0;i<size;i++){
            BTreeNode* node = q.front();
            q.pop();
            
            for(int j=0;j<node->count;j++){
                cout << node->key[j];
                if(j < node->count-1){
                    cout << " ";
                }
            }
            
            if(i < size-1){
                cout << " ";
            }
            if(node->children[0]!=NULL){
                for(int j=0;j<=node->count;j++){
                    q.push(node->children[j]);
                }
            }
        }



        cout << endl;


    }
}



void deleteNode(int x){
    if(root==NULL){
        cout << x << " not present. So it can not be deleted" << endl;
        return;
    }

    if(search(root,x) == NULL){
        cout << x << " not present. So it can not be deleted" << endl;
        return;
    }

    deleteInternal(root,x);

    if(root->count==0){
        BTreeNode* old_root = root;
        if(root->children[0]==NULL){
            root =NULL;
        }else{
            root = root->children[0];
        }

        delete old_root;

    }





    cout << x << " deleted" << endl;
    return;
}

// main program 

int main(){

    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        int key;
        cin >> key;
        insertWithoutMessage(key);
    }

    int op,value;
    while(cin >> op){
        if(op==1){
            cin >> value;
            if(search(root,value)!=NULL){
                cout << value << " present" << endl;
            }else{
                cout << value << " not present" << endl;
            }
        }else if(op==2){
            cin >> value;
            insert(value);
        }else if(op==3){
            cin >> value;
            deleteNode(value);
        }else if(op==4){
            levelOrderTraversal();
        }
    }


    return 0;
}