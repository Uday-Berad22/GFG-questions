//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<int> G[],vector<bool> &visited,vector<int> &color_set,int node,int color){
    visited[node]=true;
    bool ans=true;
    for(auto nbr: G[node]){
        if(!visited[nbr]){
                 color_set[nbr]=(!color);
                 ans=ans&&dfs(G,visited,color_set,nbr,(!color));
                 if(ans==false) return false;
        }
        else if(color_set[nbr]==color_set[node]){
            return false;
        }
    }
    return ans;
}

	bool isBipartite(int V, vector<int>G[]){
	    // Code here
	    int n=V;
     vector<bool> visited(n,false);
    vector<int> color_set(n,-1);
    int source=0;
    int flag=0;
     for(int i=0;i<n;i++){
        if(!visited[i]){
             color_set[i]=0;
             if(dfs(G,visited,color_set,i,0)==false) {
                flag=1;
                break;
             }
        }
    }
    if(flag){
        return false;
    }
        return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends