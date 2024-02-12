//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
const int M=1e9+7;
class Solution{
public:
    long long sequence(int n){
        // code here
        long long ans=0;
        int j=1;
        for(int i=1;i<=n;i++){
            long long temp=1;
            for(int k=1;k<=i;k++){
                temp=(temp*j)%M;
                j++;
            }
            ans=(ans+temp)%M;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends