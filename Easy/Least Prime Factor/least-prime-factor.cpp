//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> prime_fact(n+1);
        prime_fact[1]=1;
        for(int i=2;i<n+1;i++){
            if(prime_fact[i]==0){
                for(int j=i;j<n+1;j+=i){
                    if(prime_fact[j]==0)
                    prime_fact[j]=i;
                }
            }
        }
        return prime_fact;
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
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends