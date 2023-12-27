//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        int m=matrix.size();//number of row 
        int n=matrix[0].size();// numberof colums;
        vector<int> ans;
        for(int col=0;col<n;col++){
            int i=0,j=col;
            while(i<m&&j>=0){
                ans.push_back(matrix[i][j]);
                i+=1;
                j-=1;
            }
        }
        for(int row=1;row<m;row++){
            int i=row,j=n-1;
            while(i<m&&j>=0){
                ans.push_back(matrix[i][j]);
                i+=1;
                j-=1;
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
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends