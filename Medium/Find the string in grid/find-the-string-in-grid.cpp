//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    vector<vector<int>> searchWord(vector<vector<char>>& grid, string word) {
        vector<vector<int>> result;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == word[0]) {
                    for (int k = 0; k < 8; k++) {
                        int xDir = x[k];
                        int yDir = y[k];
                        
                        int row = i;
                        int col = j;
                        int idx = 0;
                        
                        while (idx < word.length() && row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == word[idx]) {
                            row += xDir;
                            col += yDir;
                            idx++;
                        }
                        
                        if (idx == word.length()) {
                            result.push_back({i, j});
                            break; 
                        }
                    }
                }
            }
        }
        return result;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends