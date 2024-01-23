//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    
    bool isCycle(vector<bool> &visited,int i,unordered_map<int,int> &m,unordered_map<int,int> &m2){
        if(m2[i]==0){
            return false;
        }
        if(visited[i]==true){
            return true;
        }
        visited[i]=true;
        
        bool result=isCycle(visited,m[i],m,m2);
        visited[i]=false;
        return result;
    }
    bool detect_cycle_in_directed_Graph(vector<int> G[],vector<bool> &visited,int node,vector<bool> &path_stack){
    visited[node]=true;
    path_stack[node]=true;
    bool ans=false;
    for(auto nbr: G[node]){
        if(visited[nbr]==true&&path_stack[nbr]==true){
            return true;
        }
        else if(visited[nbr]==false){
            
            ans=ans||detect_cycle_in_directed_Graph(G,visited,nbr,path_stack);
        }
    }
    path_stack[node]=false;
    return ans;
}

    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        unordered_map<int,int> m1,m2;
        vector<int>graph[n];
        for(int i=0;i<m;i++){
            m1[prerequisites[i][0]]=prerequisites[i][1];
            if(prerequisites[i][0]==prerequisites[i][1]) return {};
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            m2[prerequisites[i][0]]++;
            m2[prerequisites[i][1]]+=0;
        }
        // vector<bool> visited(n,false);
        queue<int> q;
        vector<bool> visited(n,false);
    vector<bool> path_stack(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
    if(detect_cycle_in_directed_Graph(graph,visited,i,path_stack)){
        return {};
    }}}

        for(int i=0;i<n;i++){
            
            m2[i]+=0;
            // if(visited[i]==false){
              
            if(m2[i]==0){
                q.push(i);
            }
        }
        vector<int> v;
        if(q.size()==0) return {};
        while(!q.empty()){
            int i=q.front();
            q.pop();
            v.push_back(i);
            for(auto &j: graph[i]){
                m2[j]--;
                if(m2[j]==0){
                    q.push(j);
                }
            }
        }
        return v;
        
        
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
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
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends