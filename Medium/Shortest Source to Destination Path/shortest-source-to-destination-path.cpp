//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
vector<vector<int>> direction={{1,0},{0,1},{-1,0},{0,-1}};
class Solution {
  public:
    
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(X==0&&Y==0)return 0;
        queue<pair<int,int>> q;
        int count=0;
        vector<vector<bool>> visited(N,vector<bool> (M,false));
        q.push({0,0});
        while(!q.empty()){
            int nn=q.size();
            for(int k=0;k<nn;k++){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(auto dir: direction){
                int x=i+dir[0];
                int y=j+dir[1];
                if(x<0||y<0||x>=N||y>=M)
                continue;
                else{
                    if(A[x][y]==1&&x==X&&y==Y)
                    return count+1;
                    else if(A[x][y]==1&&visited[x][y]==false){
                        q.push({x,y});
                        visited[x][y]=true;
                    }
                    // q.push()
                }
                
             }
             }
             count++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends