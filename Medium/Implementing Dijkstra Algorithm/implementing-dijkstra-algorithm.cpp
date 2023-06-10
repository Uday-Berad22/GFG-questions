//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V,0);
        priority_queue<pair<int,int>> pq;
        vector<bool> visited(V,false);
        pq.push({0,S});
        ans[S]=0;
        // 
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            if(visited[p.second]==true){
                continue;
            }
            visited[p.second]=true;
            ans[p.second]=(-1*p.first);
            for(auto a: adj[p.second]){
                if(visited[a[0]]==false){
                    pq.push({p.first-a[1],a[0]});
                }
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends