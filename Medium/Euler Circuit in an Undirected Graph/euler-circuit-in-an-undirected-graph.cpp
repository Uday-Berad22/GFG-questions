//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node,vector<bool> &visited,vector<int> adj[],int count,int v,int parent){
        visited[node]=true;
        for(auto nbr: adj[node])
        {
            if(visited[nbr]==false){
                if(dfs(nbr,visited,adj,count+1,v,node)){
                    return true;
                }
                
            }
            if(visited[nbr]==true && nbr==0 && count==v && nbr!=parent){
                return true;
            }
        }
        // visited[node]=false;
        return false;
    }
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
        
	    vector<bool> visited(v+1,false);
	    int count=0;
        for(int i=0;i<v;i++){
            count+=adj[i].size();
        }
        
        if(count==0){
            return 1;
        }
	    return dfs(0,visited,adj,1,v,0);
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends