#include<bits/stdc++.h>
using namespace std;

// main function which implements BFS algorithm on undirected graph

int main(){

    int n,m;
    cin >> n >> m;

    vector<vector<int> > adj(n+1); // adjacency list to represent graph
    vector<int> distance(n+1,-1); // shortest path length from source s to v


    vector<int> parent(n+1,-1); // predecessor of v in shortest path from s
    vector<bool> visited(n+1,false); // keep track of visited vertices

    queue<int> q;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);


    }

    int s;
    cin >> s;

    q.push(s);
    visited[s] = true;
    distance[s] = 0;

    // BFS traversal and path reconstruction

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: adj[u]){
            if(!visited[v]){
                visited[v]=true;
                distance[v] =distance[u]+1;
                parent[v]=u;
                q.push(v);
            }
        }
    }


    for(int v=1;v<=n;v++){
        cout << "Vertex " << v << ": Length = ";
        if(distance[v]==-1){
            cout << "-1, Path = Unreachable" << endl;
        }else{
            cout << distance[v] << ", Path = ";

            vector<int> path;
            int current = v;

            while(current != -1){
                path.push_back(current);
                current = parent[current];
            }
            reverse(path.begin(),path.end());

            for(int i=0;i<path.size();i++){
                cout << path[i];

                if(i < path.size()-1){
                    cout << " ";
                }
            }

            cout << endl;
        }

    }



    return 0;
}