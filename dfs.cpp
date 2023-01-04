//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs_fun(int node, int vis[], vector<int> adj[], vector<int> &dfs)
    {
        vis[node] = 1;
        dfs.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs_fun(it, vis, adj, dfs);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        int vis[V] = {0};
        int start = 0;
        // create a list to store dfs
        vector<int> dfs;
        // call dfs for starting node
        dfs_fun(start, vis, adj, dfs);
        return dfs;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends