//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
public:
    void DFS(int x,int y,vector<vector<char>> &mat,vector<vector<bool>> &visited,bool &boundary){
        int n=mat.size();
        int m=mat[0].size();
        visited[x][y]=true;
        if(boundary==false){
            mat[x][y]='X';
        }
        for(auto &dir: directions)
        {
            int xx=x+dir[0];
            int yy=y+dir[1];
            if(xx<n&&yy<m&&xx>=0&&yy>=0&&visited[xx][yy]==false&&mat[xx][yy]=='O')
                DFS(xx,yy,mat,visited,boundary);
        }       
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        bool boundary=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||i==n-1||j==0||j==m-1){
                    if(visited[i][j]==false&&mat[i][j]=='O')
                    DFS(i,j,mat,visited,boundary);
                }
            }
        }
        boundary=false;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                    if(visited[i][j]==false&&mat[i][j]=='O')
                    DFS(i,j,mat,visited,boundary);
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends