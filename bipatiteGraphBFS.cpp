//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    bool bfs(int vis[], vector<int> adj[], int V, int start)
    {
        queue<int> q;
        vis[start] = 0;
        q.push(start);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (vis[it] == -1)
                {
                    q.push(it);
                    vis[it] = !vis[node];
                }
                else if (vis[node] == vis[it])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        int vis[V];
        for (int i = 0; i < V; i++)
            vis[i] = -1;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == -1)
            {
                if (bfs(vis, adj, V, i) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends