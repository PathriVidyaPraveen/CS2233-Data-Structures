#include <bits/stdc++.h>
using namespace std;

bool BFS(int start, int target, vector<vector<int>>& adj){

    int n = adj.size();

    vector<int> visited(n, 0);

    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while (!q.empty()){


        int u = q.front();
        
        q.pop();
        if(u == target){
            return true;
        }
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    return false;
}

int main() {


    int t;

    cin >> t;

    while (t--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> adj(2*n);



        for (int i = 0; i < m; i++){
            int p, q;
            cin >> p >> q;
            int a1,b1;
            if(p>0){
                a1= p-1;
            }else{
                a1 = n-p-1;
            }

            if(q>0){
                b1 = q-1;
            }else{
                b1 = n-q-1;
            }

            int a2,b2;
            if(a1>=n){
                a2=a1-n;
            }else{
                a2=a1+n;
            }

            if(b1>=n){
                b2=b1-n;
            }else{
                b2=b1+n;
            }




            
            adj[a2].push_back(b1);
            adj[b2].push_back(a1);
        }

        bool result = true;


        for(int i = 0; i < n; i++){


            if(BFS(i,i+n, adj) && BFS(i+n,i, adj)){
                result = false;
                break;
            }

        }

        if(result){
            cout << "Satisfiable\n";
        }else{
            cout << "Unsatisfiable\n";
        }

    }
    return 0;
}