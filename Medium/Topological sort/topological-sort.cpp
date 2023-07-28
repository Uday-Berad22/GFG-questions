//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    unordered_map<int,int> m;
	    for(int i=0;i<V;i++){
	    for(auto a: adj[i]){
	        m[a]++;
	       // m[a[0]]+=0;
	       //cout<<a<<" "<<i<<endl;
	    }
	    }
	    vector<pair<int,int> > temp;
	    vector<int> ans;
	     for(int i=0;i<V;i++){
	       m[i]+=0;
	    }
	    for(auto a:m ){
	        temp.push_back({a.second,a.first});
	    }
	    sort(temp.begin(),temp.end());
	   // for(int i=0;i<V;i++){
	   //    // cout<<temp[i].first<<" "<<temp[i].second<<endl;
	   //     ans.push_back(temp[i].second);
	   //    // cout<<ans[i]<<" ";
	   // }
	   vector<bool> visited(V,false);
        queue<int> q;
	    for(int i=0;i<temp.size();i++){
	         if(temp[i].first==0){
	             q.push(temp[i].second);
	         }
	    }
    	    while(!q.empty())
            {
                int node=q.front();
                q.pop();
                // cout<<node<<" ";
                ans.push_back(node);
                visited[node]=true;
                for(auto a: adj[node]){
                    if(!visited[a]&&m[a]<=1){
                        m[a]--;
                        q.push(a);
                    }else{
                        m[a]--;
                    }
                }
            }
	   // int start
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends