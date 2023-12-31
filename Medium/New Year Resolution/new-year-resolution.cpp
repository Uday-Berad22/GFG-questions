//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int isPossible(int N , int coins[]) 
    {
        int sum=accumulate(coins,coins+N,0);
        vector<vector<int>> dp(N+1,vector<int> (sum+1,0));
        sort(coins,coins+N);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum;j++){
                if(j>=coins[i-1]){
                    if(j==coins[i-1]||dp[i-1][j-coins[i-1]]>0){
                        dp[i][j]=1;   
                    }
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
                if((j%20==0||j%24==0||j==2024)&&dp[i][j]>0) return 1;
            }
        }
        return 0;
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends