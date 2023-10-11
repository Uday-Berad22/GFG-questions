//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


vector<vector<int>> dirs={{1,0},{0,1},{0,-1},{-1,0}};
class Solution{
    map<pair<int,int> ,char> m;
    public:
    void recback(int i,int j,vector<string> &ans,string &s,vector<vector<int>> &grid,vector<vector<bool>> &visited){
        int n=grid.size();
        if(i==n-1&&j==n-1) {
            ans.push_back(s);
            return;
        }
        if(i>=n||j>=n||i<0||j<0||visited[i][j]==true) return;
        visited[i][j]=true;
        if(grid[i][j]==0) return ;
        for(auto &dir: dirs){
            s.push_back(m[{dir[0],dir[1]}]);
            recback(i+dir[0],j+dir[1],ans,s,grid,visited);
            s.pop_back();
        }
        visited[i][j]=false;
        return;
    }
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        if(grid[0][0]==0) return {};
        if(grid[n-1][n-1]==0) return {};
        vector<vector<bool>> visited(n+1,vector<bool> (n+1,false));
        vector<string> ans;
        string s="";
         m[{0,1}]='R';
        m[{1,0}]='D';
        m[{0,-1}]='L';
        m[{-1,0}]='U';
        recback(0,0,ans,s,grid,visited);
       
        return ans;
    } 
};

    
    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends