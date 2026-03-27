#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfs_cycle(vector<int>adj[],vector<bool>&vis,int first)
{
    queue <pair<int,int>> q;
    q.push({first,-1});
    vis[first]=true;

    while(q.size()>0)
    {
        int u = q.front().first;
        int par = q.front().second;
        q.pop();

        for(int neigh : adj[u])
        {
            if(!vis[neigh])
            {
                q.push({neigh,u});
                vis[neigh]=true;
            }
            else if(par!=neigh)
            {
                return true;
            }
        }
        
    }
    return false;
}
int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> adj[n+1];
    vector<bool> vis(n+1,false);
    vector<int> parent;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(bfs_cycle(adj,vis,i))
            {
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;
}
