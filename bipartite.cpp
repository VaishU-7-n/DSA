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

    vector<int> color(n+1, 0); // 0 = unvisited

    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                for(int v : adj[u]) {
                    if(color[v] == 0) {
                        color[v] = (color[u] == 1 ? 2 : 1);
                        q.push(v);
                    }
                    else if(color[v] == color[u]) {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }

    // print teams
    for(int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
}
