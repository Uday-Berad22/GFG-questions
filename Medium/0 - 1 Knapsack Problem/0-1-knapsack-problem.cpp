//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>> dp;
    int FindMaximumProfit(int wts[], int profits[], int remainWt, int i,int n)
{
    if (remainWt == 0 || i >=n)
    {
        return 0;
    }
    if (dp[remainWt][i] != -1)
    {
        return dp[remainWt][i];
    }
    // NOT TAKEN
    int maxi = FindMaximumProfit(wts, profits, remainWt, i + 1,n);

    // TAKEN
    if (remainWt - wts[i] >= 0)
        maxi = max(FindMaximumProfit(wts, profits, remainWt - wts[i], i + 1,n) + profits[i], maxi);
    return dp[remainWt][i] = maxi;
}
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       dp.assign(W + 1, vector<int>(n + 1, -1));
       return FindMaximumProfit(wt, val, W, 0,n);
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