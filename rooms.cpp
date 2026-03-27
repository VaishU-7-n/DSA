#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y,int n,int m,vector<string>&grid,vector<vector<bool>>&vis) {

    if(x < 0 || y < 0 || x >= n || y >= m) return;
    if(vis[x][y] || grid[x][y] == '#') return;

    vis[x][y] = true;

    dfs(x-1, y,n,m,grid,vis);
    dfs(x+1, y,n,m,grid,vis);
    dfs(x, y-1,n,m,grid,vis);
    dfs(x, y+1,n,m,grid,vis);
}
int main() {
    int n,m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>> vis(n,vector<bool>(m,false));

    
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }


    int rooms = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.' && !vis[i][j]) {
                dfs(i, j,n,m,grid,vis);
                rooms++;
            }
        }
    }

    cout << rooms;
}
