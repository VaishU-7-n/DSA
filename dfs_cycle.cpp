#include<iostream>
#include<vector>
using namespace std;
/*for each node we keep track of parent.
we then do dfs on the starting node and check if the node is visited the current parent should be equal to the node being visited.*/
bool dfs_cycle(int parent, vector<int> adj[],vector<bool>&vis,int first)
{
    vis[first]=true;
  

    for(int neigh : adj[first])
    {
        if(!vis[neigh])
        {
            if(dfs_cycle(first,adj,vis,neigh))
            {
                return true;
            }

        }
        else if(neigh!=parent)
        {
            return true;
        }
    }

return false;


}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector <bool> vis(n+1,false);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs_cycle(-1,adj,vis,i))
            {
                cout << 1;
                return 0;
            }

        }
    }

    cout<<0;
    
    
}
