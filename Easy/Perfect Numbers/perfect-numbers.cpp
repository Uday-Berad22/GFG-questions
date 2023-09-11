//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        long long  sum=0;
        long long  n=N;
        for(int i=1;i*1LL*i<=n;i++){
            if(n%i==0)
           {  if(i!=n)
               sum+=i;
            if(n/i!=n&&i!=n/i)
            sum+=(n/i);}
        }
        return sum==n?1:0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends