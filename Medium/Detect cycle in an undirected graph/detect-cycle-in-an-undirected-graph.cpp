//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool answer;
  public:
    // Function to detect cycle in an undirected graph.
    void dfs(vector<int> adj[],vector<bool> &visited,int node,int parent){
        visited[node]=true;
        for(auto &nbr: adj[node]){
            if(visited[nbr]==true&&parent!=nbr){
                answer=true;
            }
            else if(visited[nbr]==false)
            {
                dfs(adj,visited,nbr,node);
            }
        }
        return;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        answer=false;
        for(int i=0;i<V;i++){
            if(visited[i]==false)
            dfs(adj,visited,i,-1);
        }
        return answer;
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