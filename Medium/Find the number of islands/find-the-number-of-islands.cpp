//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define visted visited
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>> &grid,vector<vector<bool>> &visited,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n||i<0||j>=m||j<0) return;
        if(grid[i][j]=='1'&&visted[i][j]==false){
            visted[i][j]=true;
            dfs(grid,visted,i+1,j+1);
            dfs(grid,visted,i-1,j-1);
            dfs(grid,visted,i+1,j);
            dfs(grid,visted,i,j+1);
            dfs(grid,visted,i,j-1);
            dfs(grid,visted,i-1,j);
            dfs(grid,visted,i-1,j+1);
            dfs(grid,visted,i+1,j-1);
        }
        visted[i][j]=true;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(grid[i][j]=='1'&&visted[i][j]==false){
                dfs(grid,visited,i,j);
                count++;
            }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends