// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find if the given edge is a bridge in graph.

    int dfs(int i, vector<int> adj[], vector<int> &vis, int c, int d)
    {
        vis[i] = 1;
        for (auto x : adj[i])
        {
            if (i == c && x == d) continue;
            if (!vis[x]) dfs(x, adj, vis, c, d);
        }
        return 0;
    }

    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        // Code here
        vector<int> vis(100001);
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
        }

        dfs(c, adj, vis, c, d);

        return (!vis[d]);
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends