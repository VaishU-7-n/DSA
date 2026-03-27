#include<vector>
#include<iostream>
#include<queue>
using namespace std;

void bfs(vector<int>adj[], int first,int n)
{
    queue<int> q;
    q.push(first);
    vector<bool>vis(n+1,false);
    vis[first]=true;

    while(q.size()>0)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for( int v : adj[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                q.push(v);
            }

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
    bfs(adj,1,n);



}
