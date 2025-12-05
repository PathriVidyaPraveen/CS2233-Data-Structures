#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,m;
    cin >> n >> m;

    // adjacency list representation for graphs

    vector<vector<pair<int,int>>> adj(n+1);

    vector<int> key(n+1,INT_MAX); // min edge weight connecting vertex i to mst
    vector<int> parent(n+1,-1);
    vector<bool> mst_set(n+1,false);
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq; // min priority queue
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }

    int start_node = 1;
    key[start_node] = 0;

    pq.push({0,start_node});

    // start of prim algo


    while(!pq.empty()){
        int u =pq.top().second;
        pq.pop();

        if(mst_set[u]){
            continue;
        }
        mst_set[u]=true;

        for(pair<int,int> e: adj[u]){
            int v =e.first;
            int w = e.second;
            if(!mst_set[v] && w < key[v]){
                key[v]=w;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
    }

    // final output

    cout << "Edges in MST:" << endl;

    long long total_weight = 0;
    for(int i=2;i<=n;i++){
        cout << "(" << parent[i] << ", " << i << ") weight = " << key[i] << endl;
        total_weight += key[i];
    }



    cout << "Total Weight = " << total_weight << endl;



    return 0;
}