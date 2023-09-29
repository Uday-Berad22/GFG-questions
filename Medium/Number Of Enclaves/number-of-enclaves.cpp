//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<vector<int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
  public:
    void dfs(vector<vector<bool>> &visited,int i,int j,vector<vector<int>> &grid){
        if(i<0||i>=grid.size()||j>=grid[0].size()||j<0) return;
        if(visited[i][j]==true) return;
        visited[i][j]=true;
        if(grid[i][j]==1){
            for(auto &dir: dirs){
                 dfs(visited,i+dir[0],j+dir[1],grid);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        for(int i=0;i<n;i++){
                if(visited[i][0]==false){
                    dfs(visited,i,0,grid);
                }
        }
        for(int i=0;i<n;i++){
                if(visited[i][m-1]==false){
                     dfs(visited,i,m-1,grid);
                }
        }
        for(int i=0;i<m;i++){
                if(visited[0][i]==false){
                     dfs(visited,0,i,grid);
                }
        }
        for(int i=0;i<m;i++){
            if(visited[n-1][i]==false){
                 dfs(visited,n-1,i,grid);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==false&&grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends