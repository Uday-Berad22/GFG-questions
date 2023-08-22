//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int i,int W,int wt[],int val[],int n,vector<vector<int>> &dp,int cur_wt_sum){
        if(i==n)
        return 0;
        if(dp[i][cur_wt_sum]!=-1) return dp[i][cur_wt_sum];
        int x=helper(i+1,W,wt,val,n,dp,cur_wt_sum);
        int y=0;
        if(cur_wt_sum+wt[i]<=W){
            y=helper(i+1,W,wt,val,n,dp,cur_wt_sum+wt[i])+val[i];
        }
        return dp[i][cur_wt_sum]=max(x,y); 
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1,vector<int> (W+1,-1));
       return helper(0,W,wt,val,n,dp,0);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends