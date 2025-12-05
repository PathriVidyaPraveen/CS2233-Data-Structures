#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent,rank;

    public:


    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
    }
    //finds set representative

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    //union by rank

    bool unite(int x,int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY){
            return false;
        }

        if(rank[rootX] < rank[rootY]){
            parent[rootX] = rootY;
        }else if(rank[rootX] > rank[rootY]){
            parent[rootY] = rootX;
        }else{
            parent[rootY] = rootX;
            rank[rootX]++;

        }

        return true;
    }



};

int main(){

    int n,m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;

        edges.push_back({w,u,v});
    }

    // sorting all edges by weight

    sort(edges.begin(),edges.end());

    DisjointSet ds(n);

    vector<tuple<int,int,int>> mst;

    int total_weight = 0;



    // kruskal algo

    for(auto &[w,u,v] : edges){
        if(ds.unite(u,v)){
            mst.push_back({u,v,w});

            total_weight += w;
        }
    }

    cout << "Edges in MST:\n";

    for(auto &[u,v,w]: mst){
        cout << "(" << u << ", " << v << ") weight = " << w << "\n";


    }

    cout << "Total Weight = " << total_weight << "\n";


    return 0;
}