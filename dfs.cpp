#include<vector>
#include<iostream>
using namespace std;

void dfs( vector<int>adj[], vector<bool>&vis,int first )
{
    int u = first;
    cout << u <<" ";
    vis[u]=true;

    for(int v : adj[u])
    {
        if(!vis[v])
        {
            dfs(adj,vis,v);
        }

    }

}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    vector<bool>vis(n+1,false);

    dfs(adj,vis,1);



}
