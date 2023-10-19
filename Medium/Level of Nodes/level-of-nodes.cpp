//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<bool> visited(V,false);
	    queue<int> q;
	    q.push(0);
	    visited[0]=true;
	    int level=0;
	    while(!q.empty()){
	        int qsize=q.size();
	        for(int i=0;i<qsize;i++){
	            int node=q.front();
	            q.pop();
	            if(node==X) return level;
	            for(auto a: adj[node]){
	                if(visited[a]!=true){
	                    q.push(a);
	                    visited[a]=true;
	                }
	            }
	        } 
	        level++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends