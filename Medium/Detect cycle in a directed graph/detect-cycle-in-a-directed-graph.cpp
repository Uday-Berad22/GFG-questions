//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
bool detect_cycle_in_directed_Graph(vector<int> G[],vector<bool> &visited,int node,vector<bool> &path_stack){
    visited[node]=true;
    path_stack[node]=true;
    bool ans=false;
    for(auto nbr: G[node]){
        if(visited[nbr]==true&&path_stack[nbr]==true){
            return true;
        }
        else if(visited[nbr]==false){
            
            ans=ans||detect_cycle_in_directed_Graph(G,visited,nbr,path_stack);
        }
    }
    path_stack[node]=false;
    return ans;
}
    bool isCyclic(int V, vector<int> G[]) {
        // code here
        int n=V;
    vector<bool> visited(n,false);
    vector<bool> path_stack(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
    if(detect_cycle_in_directed_Graph(G,visited,i,path_stack)){
        return true;
    }}}
    return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends