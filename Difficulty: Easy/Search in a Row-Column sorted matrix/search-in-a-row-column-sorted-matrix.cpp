//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        //brute n*m
        
        
        
        // best 
        int n=mat.size();
        int m=mat[0].size();
        int i=0;
        int j=m-1;
        // if [i][j] > x j-- 
        // else if [i][j] < x i++
        //else return true
        
        while(i<n &j>=0){
            if(mat[i][j]==x){
                return true;
            }
            else if(mat[i][j]<x){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends