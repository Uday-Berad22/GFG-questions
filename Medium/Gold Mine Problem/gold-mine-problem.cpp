//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long  recurssion(int i,int j,int n,int m,vector<vector<int>> &M,vector<vector<int>> &dp){
        if(i<0||j<0||i>=n||j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int till=max(max(recurssion(i-1,j-1,n,m,M,dp),recurssion(i,j-1,n,m,M,dp)),recurssion(i+1,j-1,n,m,M,dp));
        return dp[i][j]=till+M[i][j];
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        long long  maxi=0;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        // vector<vector<int>> dp2(n,vector<int> (m,0));
        // vector<vector<int>> dp3(n,vector<int> (m,0));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0;j--){
        //         if(i+1<n&&j+1<m)
        //         dp1[i][j]=dp1[i+1][j+1];
        //         if(j+1<m)
        //         dp1[i][j]=max(dp1[i][j],dp1[i][j+1]);
        //         dp1[i][j]+=M[i][j];
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=m-1;j>=0;j--){
        //         if(i-1>=0&&j+1<m)
        //         dp2[i][j]=dp2[i-1][j+1];
        //         if(j+1<m)
        //         dp2[i][j]=max(dp2[i][j],dp2[i][j+1]);
        //         if(i+1<n&&j+1<m)
        //         dp2[i][j]=max(dp2[i][j],dp1[i+1][j+1]);
        //         dp2[i][j]+=M[i][j];
        //         dp2[i][j]=max(dp1[i][j],dp2[i][j]);
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         dp3[i][j]=max(dp1[i][j],dp2[i][j]);
        //         maxi=max(maxi,dp3[i][j]);
        //     }
        // }
        for(int i=0;i<n;i++)
        {
            maxi=max(recurssion(i,m-1,n,m,M,dp),maxi);
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