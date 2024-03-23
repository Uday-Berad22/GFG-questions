//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
      public:
    int dp[1001][1001];
    int f(int w[], int v[], int n, int tw, int i, int value){
        if(i>=n || tw==0) return 0;
        if(dp[i][tw] != -1) return dp[i][tw];
        // take if possible
        int a=0;
        if(w[i] <= tw){
            a = f(w,v,n,tw-w[i],i+1,value)+v[i];
        }
        int b = f(w,v,n,tw,i+1,value);
        return dp[i][tw] = max(a,b);
    }
    int knapSack(int tw, int w[], int v[], int n) { 
        // vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        memset(dp,-1,sizeof(dp));
       return f(w,v,n,tw,0,0);

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