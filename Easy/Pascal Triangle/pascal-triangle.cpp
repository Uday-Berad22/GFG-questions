//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
int M=1e9+7;
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        // vector<vector<long long> > dp(n,vector<long long> (n,0));
        vector<long long > dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=i;j>=0;j--){
                dp[j]=(dp[j]%M+(j-1>=0?dp[j-1]:0)%M)%M;
            }
        }
        return dp;
    }
};



//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends