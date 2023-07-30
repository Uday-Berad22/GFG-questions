//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    int find_set(int i,vector<int> &parent){
        if(parent[i]==-1) return i;
        return find_set(parent[i],parent);
    }
    void union_set(int x,int y,vector<int> &parent){
        int s1=find_set(x,parent);
        int s2=find_set(y,parent);
        if(s1!=s2){
            parent[s1]=s2;
        }
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	   map<pair<int,int>,bool> visited;
	   vector<int> parent(V,-1);
	    for(int i=0;i<V;i++){
	        for(auto nbr: adj[i]){
	            if(!visited[{i,nbr}]){
	                int s1=find_set(i,parent);
                    int s2=find_set(nbr,parent);
                    if(s1==s2) return 1;
                    else
                    union_set(i,nbr,parent);
                    visited[{nbr,i}]=true;
	            }
	        }
	    }
	    return 0;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends