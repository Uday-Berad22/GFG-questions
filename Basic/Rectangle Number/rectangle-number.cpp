//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    int mod=1e9+7;
  public:
  long long rectNum(long long N, long long M) {
        return (((((N+1)*1LL*(N))/2)%mod)*1LL*((((M+1)*1LL*(M))/2)%mod))%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N, M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.rectNum(N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends