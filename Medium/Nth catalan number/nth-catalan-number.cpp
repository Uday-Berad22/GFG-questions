//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    const int M=1e9+7;
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        
        int   dp[n+1]={0};
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i/2;j++){
                dp[i]=((2*dp[j]*1LL*dp[i-1-j])%M+dp[i]%M)%M;
            }
            if(i%2!=0){
                dp[i]=((dp[(i/2)]*1LL*dp[(i/2)])%M+dp[i]%M)%M;
            }
        }
        return dp[n];
    }
};


//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends