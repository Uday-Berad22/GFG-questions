//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	   sort(coins,coins+M);
	   vector<vector<int>> dp(M+1,vector<int> (V+1,0));
	   for(int i=1;i<=M;i++){
	       for(int j=1;j<=V;j++){

	           if(j==coins[i-1]){
	               dp[i][j]=1;
	           }
	           else if(j-coins[i-1]>=0){
	               if(dp[i-1][j]!=0&&dp[i][j-coins[i-1]]!=0){
	               dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
	               }
	               else if(dp[i-1][j]!=0){
                      dp[i][j]=dp[i-1][j];
	               }
	               else if(dp[i][j-coins[i-1]]!=0){
	                   dp[i][j]=dp[i][j-coins[i-1]]+1;
	               }
	           }
	           else{
	               dp[i][j]=dp[i-1][j];
	           }
	           }
	   }
	   //for(int i=0;i<=M;i++){
	   //    for(int j=0;j<=V;j++){
	   //        cout<<dp[i][j]<<" ";
	   //    }
	   //    cout<<endl;
	   //}
	   return dp[M][V]==0?-1:dp[M][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends