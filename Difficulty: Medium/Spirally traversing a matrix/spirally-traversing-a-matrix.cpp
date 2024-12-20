//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        
        // while count < n*m
       //  0 0 --> 0 1 --> 0 
      int n=mat.size();
      int m=mat[0].size();
      int count=0;
      vector<int> ans;
      int top=0;
      int left=0;
      int i=0;
      int j=0;
      int total=n*m;
      while(count<total){
          while(j<m && i>=top && i<n){
              ans.push_back(mat[i][j]);
              j++;
              count++;
          }
          top++;
          i++;
          j--;
          while(i<n && j>=left && j<m){
              ans.push_back(mat[i][j]);
              i++;
              count++;
          }
          i--;
          j--;
          m--;
          while(j>=left && i>=top && i<n){
              ans.push_back(mat[i][j]);
              j--;
              count++;
          }
        //   left++;
          j++;
          i--;
          while(i>=top && j<m && j>=left){
              ans.push_back(mat[i][j]);
              i--;
              count++;
          }
          
          left++;
          i++;
          j++;
          n--;
      }
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends