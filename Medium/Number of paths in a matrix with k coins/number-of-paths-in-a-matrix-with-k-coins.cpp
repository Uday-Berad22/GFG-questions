//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long rec(int n,int i,int j,int k,int sum,vector<vector<int>> &arr,vector<vector<vector<long long >>> &dp){
        if(i>=n||j>=n) return 0;
        if(i==n-1&&j==n-1){
            if(sum+arr[i][j]==k) return 1;
            return 0;
        }
        if(sum+arr[i][j]>k){
            return 0;
        }
        if(dp[i][j][sum]!=-1)return dp[i][j][sum];
        long long  a=rec(n,i+1,j,k,sum+arr[i][j],arr,dp);
        long long  b=0;
            b=rec(n,i,j+1,k,sum+arr[i][j],arr,dp);
        return dp[i][j][sum]= a+b;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        // Code Here
        vector<vector<vector<long long >>> dp(n+1,vector<vector<long long > > (n+1,vector<long long > (k+1,-1)));
        return rec(n,0,0,k,0,arr,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends