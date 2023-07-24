//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect_cycle_in_Graph(vector<int> G[],vector<bool> &visited,int node,int parent){
    visited[node]=true;
    bool ans=false;
    for(auto nbr: G[node]){
        if(visited[nbr]==true&&nbr!=parent){
            return true;
        }
        else if(visited[nbr]==false){
            ans=ans||detect_cycle_in_Graph(G,visited,nbr,node);
        }
    }
    return ans;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
           vector<bool> visited(V,false);
           for(int i=0;i<V;i++){
               if(!visited[i]){
                 if(detect_cycle_in_Graph(adj,visited,i,i)){
                     return true;
                }
               }
           }
            return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends