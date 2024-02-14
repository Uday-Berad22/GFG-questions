//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    	bool toposortDFS(int i,int V,vector<int> adj[],vector<bool> &visited,vector<int> &stk) {
	    visited[i]=true;
	    stk[i]=true;
	    bool ans=true;
	    for(int j=0;j<adj[i].size();j++){
	        if(!visited[adj[i][j]]){
	            ans=ans&&toposortDFS(adj[i][j],V,adj,visited,stk);
	        }
	        else if(visited[adj[i][j]]==true && stk[adj[i][j]]==true){
	            return false;
	        }
	    }
	    stk[i]=false;
	    return ans;
	}
	
	bool topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    vector<int> stk(V,false);
	    vector<bool> visited(V,false);
	    for(int i=0;i<V;i++)
    	    if(!visited[i])
    	        if(toposortDFS(i,V,adj,visited,stk)==false) return false;
	    return true;
	}
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        if(topoSort(V,adj)==false) return true;
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