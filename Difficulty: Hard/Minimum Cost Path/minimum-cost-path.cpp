//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	vector<vector<int>> dir={{-1,0},{0,1},{0,-1},{1,0}};
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({grid[0][0],{0,0}});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m,1e9));
        // vector<vector<
        visited[0][0]=grid[0][0];
        while(!pq.empty()){
            auto p=pq.top();
            int i=p.second.first;
            int j=p.second.second;
            int cost=p.first;
            if(i==n-1 && j==m-1){
                return cost;
            }
            pq.pop();
            visited[i][j]=true;
            
            for(auto d: dir){
                if(i+d[0]>=n || i+d[0]<0 || j+d[1]>=m || j+d[1]<0){
                    continue;
                }
                if(visited[i+d[0]][j+d[1]]<=cost+grid[i+d[0]][j+d[1]]) continue;
                visited[i+d[0]][j+d[1]]=cost+grid[i+d[0]][j+d[1]];
                pq.push({cost+grid[i+d[0]][j+d[1]],{i+d[0],j+d[1]}});
            }
        }
        return INT_MAX;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends