//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    const int M=1e9+7;
  public:
    int firstElement(int n) {
        // code here
        int a=1;
        int b=1;
        int c=2;
        
        for(int i=3;i<=n;i++){
            c=(a+b)%M;
            a=b;
            b=c;
        }
        return b%M;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends