#include<bits/stdc++.h>
using namespace std;


int result = 0; // final answer to output

vector<vector<int> > adjacency;

vector<int> node_values;
// dfs is done , u = cuerrent node , parent = parent node of u , returns length of longest downward path which have equal nodes starting from u

int dfs(int u , int parent){


    int max1 = 0 , max2 = 0;

    for(int v : adjacency[u]){
        if(v == parent){
            continue;
        }

        int child_path_length = dfs(v,u);

        if(node_values[v] == node_values[u]){
            if(child_path_length > max1){
                max2 = max1;
                max1 = child_path_length;
            }else if(child_path_length > max2){
                max2 = child_path_length;
            }
        }

    



    }



    if(1 + max1 + max2 > result){
        result = 1 + max1 + max2;
    }



    return 1 + max1;



}





int main(){

int n;
cin >> n;

if(n == 0){
    cout << 0 << endl;
    return 0;
}

    node_values.resize(n+1);
    adjacency.resize(n+1);



    for(int i=1;i<=n;i++){
        cin >> node_values[i];
    }


    for(int i=0;i<n-1;i++){
        int u , v;
        cin >> u >> v;


        adjacency[u].push_back(v);
        adjacency[v].push_back(u);


    }

    result = 1;
    dfs(1,0);

    cout << result << endl;





    return 0;
}