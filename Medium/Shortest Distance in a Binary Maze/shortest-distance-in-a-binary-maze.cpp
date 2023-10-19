//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        queue<pair<int,int> >  q;
        int count=0;
        q.push(source);
        int n=grid[0].size();
        int m=grid.size();
        if(source==destination) return 0;
        while(!q.empty()){
            count++;
            int qsize=q.size();
            while(qsize--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto &dir:directions){
                    int xx=x+dir[0];
                    int yy=y+dir[1];
                    if(destination.first==xx&&destination.second==yy){
                        return count;
                    }
                    if(xx>=0&&xx<m&&yy<n&&y>=0&&grid[xx][yy]==1){
                        q.push({xx,yy});
                        grid[xx][yy]=-1;
                    }
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends