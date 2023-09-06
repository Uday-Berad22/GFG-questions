//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define v V
class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int i,int V,vector<int>adj[],int &count,vector<bool> &visited){
            count++;
            visited[i]=true;
            for(auto a: adj[i]){
                if(visited[a]!=true){
                      dfs(a,V,adj,count,visited);
                }
            }
            // visited[i]=false;
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> visited(V,false);
	    int ans=0;
	    for(int i=0;i<V;i++){
	        
	        if(visited[i]==false){
	            int count=0;
	            dfs(i,V,adj,count,visited);
	            ans=i;
	            if(count==V) return i;
	        }
	    }
	    visited.assign(V,false);
	    int  count=0;
	    dfs(ans,V,adj,count,visited);
	    if(count==v) return ans;
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends