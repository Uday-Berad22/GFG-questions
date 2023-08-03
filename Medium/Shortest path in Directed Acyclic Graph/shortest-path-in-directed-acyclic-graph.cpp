//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> G(N);
        vector<int> ans(N,INT_MAX);
        ans[0]=0;
        for(auto a: edges){

                G[a[0]].push_back({a[1],a[2]});

        }
        priority_queue<pair<int,int>> pq;
        vector<bool> visited(N,false);
        pq.push({0,0});
        visited[0]=true;
        while(!pq.empty()){
            int node=pq.top().second;
            int val=pq.top().first;
            ans[node]=min(-1*val,ans[node]);
            pq.pop();
            // if(visited[node]==true){
            //     continue;
            // }
            for(auto nbr: G[node]){
                // if(visited[nbr.first]==false){
                if(-1*(val+(-1)*nbr.second)<ans[nbr.first])
                pq.push({val+(-1)*nbr.second,nbr.first});
                visited[nbr.first]=true;
                // }
            }
        }
        for(int i=0;i<N;i++){
            if(ans[i]==INT_MAX) ans[i]=-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends