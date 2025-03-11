//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(int n) {
        // your code here
        vector<int> dp(n+2,0);
        dp[0]=1;
        dp[1]=1;
        for(int j=2;j<=n;j++){
          dp[j]=dp[j-1]+dp[j-2];   
        }
        return dp[n];
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends