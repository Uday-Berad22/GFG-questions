//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
    void DFS(vector<vector<int>> &grid,vector<vector<bool>> &visited,int x,int y,set<vector<pair<int,int>>> &s,int baseX,int baseY,vector<pair<int,int>> &temp){
        int m=grid.size();
        int n=grid[0].size();
        visited[x][y]=true;
        pair<int,int> p={x-baseX,y-baseY};
        temp.push_back(p);
        for(auto &dir: directions){
            int xx=x+dir[0];
            int yy=y+dir[1];
            if(xx<m&&yy<n&&xx>=0&&yy>=0&&grid[xx][yy]==1&&visited[xx][yy]==false){
                DFS(grid,visited,xx,yy,s,baseX,baseY,temp);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m=grid.size();//Num of rows
        int n=grid[0].size();// Num of cols
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        vector<pair<int,int>> temp;
        set<vector<pair<int,int>>> s;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==false&&grid[i][j]==1){
                    DFS(grid,visited,i,j,s,i,j,temp);
                    s.insert(temp);
                    temp.clear();
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends