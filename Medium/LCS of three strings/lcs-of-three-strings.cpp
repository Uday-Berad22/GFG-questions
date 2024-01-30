//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int rec(int i,int j,int k,string &A,string &B,string &C,vector<vector<vector<int>>> &dp){
        if(i>=A.size()||j>=B.size()||k>C.size()) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(A[i]==B[j]&&B[j]==C[k]){
            return dp[i][j][k]=rec(i+1,j+1,k+1,A,B,C,dp)+1;
        }
        
        return  dp[i][j][k]=max({rec(i+1,j,k,A,B,C,dp),rec(i,j+1,k,A,B,C,dp), rec(i,j,k+1,A,B,C,dp)});
    }
    public:

        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            vector<vector<vector<int>>> dp(n1+1,vector<vector<int>> (n2+1,vector<int> (n3+1,-1)));
            return rec(0,0,0,A,B,C,dp);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends