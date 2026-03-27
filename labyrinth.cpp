#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> move(n, vector<char>(m));

    int sx, sy, ex, ey;

    // find A and B
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                sx = i; sy = j;
            }
            if(grid[i][j] == 'B') {
                ex = i; ey = j;
            }
        }
    }

    // BFS
    queue<pair<int,int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if(!vis[nx][ny] && grid[nx][ny] != '#') {
                    vis[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    move[nx][ny] = dir[i];
                    q.push({nx, ny});
                }
            }
        }
    }

    // check if reachable
    if(!vis[ex][ey]) {
        cout << "NO\n";
        return 0;
    }

    // reconstruct path
    string path = "";
    int x = ex, y = ey;

    while(x != sx || y != sy) {
        path += move[x][y];
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";
}
