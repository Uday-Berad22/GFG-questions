//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<int> ans;
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<bool> &visited,vector<int> G[]){
    visited[node]=true;
    ans.push_back(node);
    for(auto nbr : G[node]){
        if(!visited[nbr]){
            dfs(nbr,visited,G);
        }
    }
    return;
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<bool> visited(v,false);
        dfs(0,visited,adj);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends