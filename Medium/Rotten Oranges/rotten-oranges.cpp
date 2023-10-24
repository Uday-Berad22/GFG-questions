//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int mul=n*m;
        queue<int> q;
        int count=0;
        int t=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int index=(i*mul)+j;
                if(grid[i][j]==2){
                    q.push(index);
                }
                else if(grid[i][j]==1)
                count++;
            }
        }
        if(count==0) return 0;
        vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int levelsize=q.size();//Oranges rotten at time t
            while(levelsize--){
                int index=q.front();
                q.pop();
                int x=index/mul;
                int y=index%mul;
                for(auto &dir: directions){
                    int xx=x+dir[0];
                    int yy=y+dir[1];
                    int newIndex=xx*mul+yy;
                    if(x+dir[0]>=0&&y+dir[1]>=0&&x+dir[0]<n&&y+dir[1]<m&&grid[xx][yy]==1){
                        q.push(newIndex);
                        grid[xx][yy]=2;
                        count--;
                    }
                }
            }
            t++;
        }
        return count==0?t-1:-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends