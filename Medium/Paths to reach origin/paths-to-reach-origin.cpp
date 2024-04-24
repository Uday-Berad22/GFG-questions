//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
    int M=1e9+7;
public:
    int rec(int x,int y,vector<vector<int>> &dp,int m,int n){
       if(y<0 ||x<0){
           return 0;
       }
       if(x==0 && y==0){
           return 1;
       }
       if(dp[x][y]!=-1) return dp[x][y]%M;
       return dp[x][y]=(rec(x-1,y,dp,m,n)+rec(x,y-1,dp,m,n))%M;
    }
    int ways(int x, int y)
    {
        //code here.
        vector<vector<int>> dp(x+1,vector<int> (y+1,-1));
        return rec(x,y,dp,0,0);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends