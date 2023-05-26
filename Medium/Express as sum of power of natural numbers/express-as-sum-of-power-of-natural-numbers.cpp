//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
const int M=1e9+7;

class Solution{
    public:
    int numOfWays(int n, int x)
    {
         double high=n;
        double low=0;
        while(high-low>=0.000000001){
            double mid=(high+low)/2;
            if(pow(mid,x)>=n){
                high=mid;
            }
            else{
                low=mid;
            }
        }
        // cout<<high<<endl;
        int m=high;
        // // /
        int sum=n;
        long long num;
         vector<vector<int>> dp(m+1,vector<int> (sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<m+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j==0){
                    dp[i][j]=1;
                    continue;
                }
                num=pow(i,x);
                if(num>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-num])%M;
                }
            }
        }
        //  for(int i=0;i<n+1;i++){
        //     for(int j=0;j<sum+1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[m][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends