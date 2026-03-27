#include<iostream>
#include<vector>
#include<queue>
using namespace std;


bool cycle(int first,vector<int>adj[],vector<bool>&vis,vector<bool>&path)
{
    path[first]=true;
    vis[first]=true;

    for(int neigh : adj[first])
    {
        if(!vis[neigh])
        {
            if(cycle(neigh,adj,vis,path))
            {
                return true;
            }
        }
        else if(path[neigh])
        {
            return true;
        }
    
    }

    path[first]=false;
    return false;

}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<bool>vis(n+1,false);
    vector<bool>path(n+1,false);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >>v;
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cycle(i,adj,vis,path);

        }
    }
}
