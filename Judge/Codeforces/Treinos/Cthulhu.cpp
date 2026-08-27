#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
vector<int> adj[MAXN];
bool vis[MAXN];

// dfs
void dfs(int u){
    vis[u] = true;
    
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main()
{
    int n, m; 
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if(n != m){
        cout << "NO" << "\n"; 
        return 0;
    }
    
    dfs(1);
    
    bool conexo = true;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            conexo = false;
        }
    }
    
    if(conexo){
        cout << "FHTAGN!" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }

    return 0;
}
