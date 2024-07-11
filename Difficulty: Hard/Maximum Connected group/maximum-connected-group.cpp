//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  unordered_map<int,int> ht;
  int n,flag;
  int dx[4]={1,-1,0,0};
  int dy[4]={0,0,1,-1};
  void bfs(vector<vector<int>>& a,int i,int j,vector<vector<int>>& v)
  {
      v[i][j]=flag;
      queue<pair<int,int>> q;
      q.push({i,j});
      int c=0;
      while(q.empty()==false)
      {
          auto z=q.front();
          q.pop();
          c++;
          int x=z.first;
          int y=z.second;
          for(int k=0;k<4;k++)
          {
              int nx=x+dx[k];
              int ny=y+dy[k];
              if(nx<0||ny<0||nx==n||ny==n||v[nx][ny]>0||a[nx][ny]==0)
                continue;
              v[nx][ny]=flag;
              q.push({nx,ny});
          }
      }
      ht[flag]=c;
      return;
  }
    int MaxConnection(vector<vector<int>>& a) 
    {
        flag=1;
        n=a.size();
        ht.clear();
        vector<vector<int>> v(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1 and v[i][j]==0)
                {
                    bfs(a,i,j,v);
                    flag++;
                }
            }
        }
        int ans=1;
        for(auto& x:ht)
            ans=max(ans,x.second);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==0)
                {
                    int c=1;
                    unordered_map<int,int> t;
                    for(int z=0;z<4;z++)
                    {
                        int ni=i+dx[z];
                        int nj=j+dy[z];
                        if(ni<0||nj<0||ni==n||nj==n||v[ni][nj]==0||t[v[ni][nj]]!=0)
                            continue;
                        t[v[ni][nj]]=ht[v[ni][nj]];
                        c=c+ht[v[ni][nj]];
                    }
                    ans=max(ans,c);
                }
            }
        }
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
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends