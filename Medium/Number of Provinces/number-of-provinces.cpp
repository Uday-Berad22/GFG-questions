//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<bool> & visited,vector<vector<int>> &adj,int i){
        visited[i]=true;
        for(int j=0;j<adj.size();j++){
            if(!visited[j]&&adj[i][j]==1){
                dfs(visited,adj,j);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here'
        int count=0;
        vector<bool > visited(V,false);
        for(int i=0;i<V;i++){
                if(!visited[i]){
                     dfs(visited,adj,i);
                     count++;
                }
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