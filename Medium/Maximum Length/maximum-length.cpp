//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        int m=max(a,max(b,c));
        int ans=0;
        if(m==a){
            ans=b+c;
        }
        else if(m==b){
            ans=a+c;
        }
        else{
            ans=a+b;
        }
        m-=2;
        // cout<<m<<endl;
        if(m<=2*ans){
            return a+b+c;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends