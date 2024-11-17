//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        // vector<vector<pair<>> graph(adj.size());
        // for(int  i=0;i<adj.size();i++){
        //     for(auto p: adj[i]){
        //         graph[i].push_back()
        //     }
        // }
        vector<int> ans(adj.size(),INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(adj.size(),false);
        ans[src]=0;
        // visited[src]=true;
        pq.push({0,src});
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            if(visited[p.second]==true){
                continue;
            }
            visited[p.second]=true;
            ans[p.second]=(p.first);
            for(auto a: adj[p.second]){
                if(visited[a.first]==false){
                    pq.push({p.first+a.second,a.first});
                }
            }
        }

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
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends