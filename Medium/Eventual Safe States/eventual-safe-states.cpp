//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool fun(int i,vector<int> adj[],vector<int> &ans,vector<bool> &visited,vector<bool> &V){
        if(adj[i].size()==0){ if(visited[i]==false)ans.push_back(i);visited[i]=true;return true;}
        if(visited[i]==true) return V[i];
        bool flag=true;
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++){
            flag=flag&&fun(adj[i][j],adj,ans,visited,V);
        }
        if(flag==true){
            ans.push_back(i);
        }
        return V[i]=flag;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        vector<bool> visited(V,false);
        vector<bool> v(V);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                fun(i,adj,ans,visited,v);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends