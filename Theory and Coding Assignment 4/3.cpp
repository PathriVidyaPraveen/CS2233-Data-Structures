#include<bits/stdc++.h>
using namespace std;

// reconstruct and print shortest path from source to vertex

void print(int v,vector<int> parent){
    vector<int> path;
    int current = v;

    while(current != -1){
        path.push_back(current);
        current = parent[current];


    }

    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++){
        cout << path[i];
        if(i!=path.size()-1){
            cout << " ";
        }
    }
}


int main(){

    int n,m;
    cin >> n >> m;

    // adjacency list representation of graph

    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    int s;
    cin >> s;
    
    vector<long long> distance(n+1,numeric_limits<long long>::max());
    vector<int> parent(n+1,-1);

    // min priority queue
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

    distance[s]=0;
    pq.push({0,s});


    // djikstra algo
    while(!pq.empty()){
        long long d = pq.top().first;

        int u = pq.top().second;
        pq.pop();
        if(d>distance[u]){
            continue;
        }
        for(pair<int,int> e : adj[u]){
            int v = e.first;
            int w = e.second;

            if(distance[v] >= distance[u] + w){
                distance[v] = distance[u] + w;
                parent[v]=u;
                pq.push({distance[v],v});
            }
        }

    }

    // final output

    for(int v=1;v<=n;v++){
        cout << "Vertex " << v << ": ";
        if(distance[v] == numeric_limits<long long>::max()){
            cout << "Length = -1, Path = Unreachable\n";
        }else{
            cout << "Length = " << distance[v] << ", Path = ";
            print(v,parent);

            cout << "\n";
        }
    }



    return 0;
}