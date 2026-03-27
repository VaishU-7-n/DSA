#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    vector<int> parent(n+1, -1);

    queue<int> q;
    q.push(1);
    vis[1] = true;

    // BFS
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(!vis[v]) {
                vis[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // if not reachable
    if(!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // reconstruct path
    vector<int> path;
    int cur = n;

    while(cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(int x : path) cout << x << " ";
}
