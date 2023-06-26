//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const int M=1e9+7;
class Solution{
public:
    int binary_expo(int a,int b){
        int ans=1;
        while(b>0){
            if(b&1){
                ans=(ans*1LL*a)%M;
            }
            a=(a*1LL*a)%M;
            b=b>>1;
        }
        return ans;
    }
    
    int nCr(int n, int r){
        // code here
        if(n<r) return 0;
        int fact[1001];
        fact[0]=1;
        for(int i=1;i<=n;i++){
            fact[i]=(fact[i-1]*1LL*i)%M;
        }
        int num=fact[n];
        int deno=(fact[r]*1LL*fact[n-r])%M;
        num=(num*1LL*binary_expo(deno,M-2))%M;
        return num;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends