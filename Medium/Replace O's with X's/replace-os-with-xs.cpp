//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
public:
   void dfs1(vector<vector<bool> > & visited,int i,int j,int &N,int &M,vector<vector<char>>& matrix){
       if((i==N||j==M)||(i<0||j<0)){
           return;
       }
       if(visited[i][j]==true||matrix[i][j]=='X'){
           return ;
       }
       visited[i][j]=true;
       dfs1(visited,i+1,j,N,M,matrix);
       dfs1(visited,i-1,j,N,M,matrix);
       dfs1(visited,i,j+1,N,M,matrix);
       dfs1(visited,i,j-1,N,M,matrix);
    }
   void dfs(vector<vector<bool> > & visited,int i,int j,int &N,int &M,vector<vector<char>>& matrix){
       if((i==N||j==M)||(i<0||j<0)){
           return;
       }
       if(visited[i][j]==true||matrix[i][j]=='X'){
           return ;
       }
       visited[i][j]=true;
       dfs(visited,i+1,j,N,M,matrix);
       dfs(visited,i-1,j,N,M,matrix);
       dfs(visited,i,j+1,N,M,matrix);
       dfs(visited,i,j-1,N,M,matrix);
       matrix[i][j]='X';
    }

    vector<vector<char>> fill(int N, int M, vector<vector<char>> &matrix)
    {
        // code here
       vector<vector<bool>> visited(N,vector<bool> (M,false));
        for(int i=0;i<M;i++){
            if(matrix[0][i]=='O'&&visited[0][i]==false){
                 dfs1(visited,0,i,N,M,matrix);
            }
        }
        for(int i=1;i<N;i++){
            if(matrix[i][0]=='O'&&visited[i][0]==false){
                 dfs1(visited,i,0,N,M,matrix);
            }
        }
        for(int i=0;i<M;i++){
            if(matrix[N-1][i]=='O'&&visited[N-1][i]==false){
              dfs1(visited,N-1,i,N,M,matrix);
            }
        }
        for(int i=1;i<N;i++){
            if(matrix[i][M-1]=='O'&&visited[i][M-1]==false){
                 dfs1(visited,i,M-1,N,M,matrix);
            }
        }
        int count=0;
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(matrix[i][j]=='O'&&visited[i][j]==false){
                   dfs(visited,i,j,N,M,matrix);
                   count++;
                }
            }
        }
        return matrix;
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