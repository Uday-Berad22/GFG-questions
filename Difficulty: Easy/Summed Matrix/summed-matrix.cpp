//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
         // code here
        long ans=0;
      if(q>n+n){
          ans= 0L;
      }else{
          if(q==n+1){
             ans= n;
          }else if(q<n+1){
              ans= q-1;
          }else{
             ans= (n+n-q+1);
          }
      }
      
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends