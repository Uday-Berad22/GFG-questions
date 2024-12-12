//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if(n<r){
            return 0;
        }
        long long ans=1;
        long long  den=1;
        r=min(r,n-r);
        while(r>0){
            ans=(ans*n);
            den=den*r;
            if(ans%den==0){
                ans=ans/den;
                den=1;
            }
            
            n--;
            r--;
        }
        return ans/den;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends