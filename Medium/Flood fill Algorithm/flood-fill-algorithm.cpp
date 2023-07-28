//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
public:
   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size();
        int m=image[0].size();
        int color=image[sr][sc];
        queue<pair<int,int>> q;
        image[sr][sc]=newColor;
        q.push({sr,sc});
        vector<vector<bool>> visited(n,vector<bool> (m,false) );
        visited[sr][sc]=true;
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(auto a: dir){
                int i=x+a[0],j=y+a[1];
                if(i<0||j<0||i>=n||j>=m)
                continue;
                if(!visited[i][j]&&image[i][j]==color){
                q.push({i,j});
                visited[i][j]=true;
                image[i][j]=newColor;
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends