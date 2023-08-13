//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    const int M=1e9+7;
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        vector<long long > cur(n,0),prev(n,0);
        prev[n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(j+1>=n){
                    cur[j]=prev[j];
                }
                else{
                    cur[j]=(prev[j]+cur[j+1])%M;
                }
            }
            prev=cur;
        }
        return prev[0]%M;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends