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

// helper function to find the depth of given node from root of depth 0

int findNodeDepth(Node* root, int value, int depth){
    if(root == NULL){
        return -1;
    }

    if(root->data == value){
        return depth;
    }


    int left_depth = findNodeDepth(root->left,value,depth+1);
    if(left_depth != -1){
        return left_depth;
    }else{
        int right_depth = findNodeDepth(root->right,value,depth+1);
        return right_depth;
    }



    return -1;
}


// helper function to find the least common ancestor of 2 given values


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


// helper function to find out distance between 2 nodes using LCA and depth formula

int distanceBetweenNodes(Node* root , int value1 , int value2){
    if(value1 == value2){
        return 0;
    }

    Node* lca = LCA(root,value1,value2);
    if(lca == NULL){
        return -1;
    }

    int depth1 = findNodeDepth(root,value1,0);
    int depth2 = findNodeDepth(root,value2,0);
    int depth_lca = findNodeDepth(root,lca->data,0);


    int distance = depth1 + depth2 - 2* depth_lca;

    return distance;
}


// helper function to collect all nodes into a vector



void getAllNodes(Node* root,vector<int>& all_nodes){
    if(root == NULL){
        return;
    }

    all_nodes.push_back(root->data);
    getAllNodes(root->left,all_nodes);
    getAllNodes(root->right,all_nodes);


    return;
}

// finds the most frequent distance(n = no of nodes)

int mostFrequentDistance(Node* root,int n){
    if(n <=1){
        return 0;
    }


    vector<int> all_nodes;
    getAllNodes(root,all_nodes);


    map<int,int> frequency_map;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int distance = distanceBetweenNodes(root,all_nodes[i],all_nodes[j]);
            if(distance >= 0){
                frequency_map[distance]++ ;
            }
        }
    }

    int max_frequency = -1;
    int result = -1;

    for(pair<int,int> x : frequency_map){
        int distance = x.first;
        int frequency = x.second;

        if(frequency > max_frequency){
            max_frequency = frequency;
            result = distance;
        }
    }


return result;

}




int main(){

   int n;
    cin >> n;
    

    if(n == 0){
        cout << 0 << endl;
        return 0;
    }

    preorder.resize(n);
    for(int i=0;i<n;i++){
        cin >> preorder[i];
    }

    vector<int> inorder(n);
    for(int i=0;i<n;i++){
        cin >> inorder[i];
    }


    pre_index = 0;
    error_flag = false;
    Node* root = buildTree(inorder,0,n-1,n);


    int result = mostFrequentDistance(root,n);

    cout << result << endl;

    


    return 0;
}