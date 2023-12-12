//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long  recurssion_Memoization(int i,int j,int n,int m,vector<vector<int>> &M,vector<vector<int>> &dp){
        if(i<0||j<0||i>=n||j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int till=max(max(recurssion_Memoization(i-1,j-1,n,m,M,dp),recurssion_Memoization(i,j-1,n,m,M,dp)),recurssion_Memoization(i+1,j-1,n,m,M,dp));
        return dp[i][j]=till+M[i][j];
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int  maxi=0;
        vector<vector<int>> dp(n,vector<int> (m,0));
        // for(int i=0;i<n;i++)
        // {
        //     maxi=max(recurssion_Memoization(i,m-1,n,m,M,dp),maxi);
        // }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                dp[i][j]=max(max((i-1>=0&&j-1>=0?dp[i-1][j-1]:0),(i+1<n&&j-1>=0?dp[i+1][j-1]:0)),(j-1>=0?dp[i][j-1]:0));
                dp[i][j]+=M[i][j];
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends