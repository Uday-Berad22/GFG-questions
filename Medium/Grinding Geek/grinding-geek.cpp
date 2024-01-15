//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int rec(int i,int price,vector<int> &cost,vector<vector<int>> &dp){
        int n=cost.size();
        if(i>=n) return 0;
        if(dp[i][price]!=-1) return dp[i][price];
        int a=INT_MIN;
        if(price>=cost[i])
        a=rec(i+1,price-(0.1*cost[i]),cost,dp)+1;
        int b=rec(i+1,price,cost,dp);
        return dp[i][price]=max(a,b);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        vector<vector<int>> dp(n+1,vector<int> (total+1,-1));
        return rec(0,total,cost,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends