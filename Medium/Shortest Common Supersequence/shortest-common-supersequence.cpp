//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int n, int m)
    {
        //code here
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                if(X[i-1]==Y[j-1]){
                    dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
                }
            }
        }
        return m+n-dp[n][m];
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends