//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   long long int solve(int n,int num,vector<vector<int>>&moves,vector<vector<long long int>>&dp){
        if(n==0){
            return 1;
        }
        if(dp[n][num]!=-1){
            return dp[n][num];
        }
        long long int ans=0;
        vector<int>mapping=moves[num];
        for(int j=0;j<mapping.size();j++){
            ans+=solve(n-1,mapping[j],moves,dp);
        }
        return dp[n][num]=ans;
    }
  public:
    long long getCount(int n) {
        // if(n==1){
        //     return 10;
        // }
           vector<vector<int>> moves={{0,8},{1,2,4},{2,1,3,5},{3,2,6},
        {4,1,5,7},{5,2,4,6,8},{6,3,5,9},{7,4,8},{8,5,7,9,0},{9,6,8}};
        vector<vector<long long int>>dp(30,vector<long long int>(11,-1));
        long long int ans=0;
        for(int i=0;i<=9;i++){
            ans+=solve(n-1,i,moves,dp);
        }
        
        
        
        return ans;


    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends