//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int fun(int i,int j,int n,int m,int a[],int b[],vector<vector<int>> &dp,int z){
	    if(j==m) return 0;
	    if(i==n) return -1e7;
	    if(dp[i][j]!=-1) return dp[i][j];
	    int cur1=fun(i+1,j,n,m,a,b,dp,z+1);
	    int cur2=(a[i]*b[j])+fun(i+1,j+1,n,m,a,b,dp,z);
	    int maxi=max(cur1,cur2);
	    return dp[i][j]=maxi;
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		vector<vector<int>> dp(n,vector<int> (m,-1));
		return fun(0,0,n,m,a,b,dp,0);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends