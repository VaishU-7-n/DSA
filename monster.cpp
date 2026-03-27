#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> monster(n, vector<int>(m, 1e9));
    queue<pair<int,int>> q;

    int sx, sy;

    // initialize
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'M') {
                q.push({i,j});
                monster[i][j] = 0;
            }
            if(grid[i][j] == 'A') {
                sx = i;
                sy = j;
            }
        }
    }

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    // 🧟 Monster BFS
    while(!q.empty()) {
        auto [x,y] = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m) {
                if(grid[nx][ny] != '#' && monster[nx][ny] == 1e9) {
                    monster[nx][ny] = monster[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }

    // 🧍 Your BFS
    queue<pair<int,int>> q2;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> move(n, vector<char>(m));

    q2.push({sx, sy});
    dist[sx][sy] = 0;

    while(!q2.empty()) {
        auto [x,y] = q2.front(); q2.pop();

        // ✅ escape if boundary
        if(x == 0 || y == 0 || x == n-1 || y == m-1) {
            // reconstruct path
            string path = "";
            int cx = x, cy = y;

            while(cx != sx || cy != sy) {
                path += move[cx][cy];
                auto p = parent[cx][cy];
                cx = p.first;
                cy = p.second;
            }

            reverse(path.begin(), path.end());

            cout << "YES\n";
            cout << path.size() << "\n";
            cout << path << "\n";
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m) {
                if(grid[nx][ny] != '#' && dist[nx][ny] == -1) {

                    // 🔥 crucial condition
                    if(dist[x][y] + 1 < monster[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + 1;
                        parent[nx][ny] = {x,y};
                    }

                    char dir;
                    if(i==0) dir='U';
                    if(i==1) dir='D';
                    if(i==2) dir='L';
                    if(i==3) dir='R';

                    move[nx][ny] = dir;
                    q2.push({nx,ny});
                }
            }
        }
    }

    cout << "NO\n";
}
