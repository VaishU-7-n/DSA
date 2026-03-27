#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool>& vis) {
    vis[node] = true;

    for(int neigh : adj[node]) {
        if(!vis[neigh]) {
            dfs(neigh, adj, vis);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    vector<int> reps; // representatives of components

    // find components
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            reps.push_back(i);
            dfs(i, adj, vis);
        }
    }

    // number of new roads
    cout << reps.size() - 1 << "\n";

    // connect components
    for(int i = 1; i < reps.size(); i++) {
        cout << reps[i-1] << " " << reps[i] << "\n";
    }
}
