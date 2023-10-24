//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<bool> &visited,vector<vector<int>> &adj,int n,int node){
        for(int i=0;i<n;i++){
            if(adj[node][i]==1&&visited[i]!=true){
                visited[i]=true;
                dfs(visited,adj,n,i);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V,false);
        int count=0;
        for(int i=0;i<V;i++)
        if(visited[i]!=true){
            visited[i]=true;
            dfs(visited,adj,V,i);
            count++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends