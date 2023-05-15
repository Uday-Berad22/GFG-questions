//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        long long ans=0;
        int n=log2(N)+1;
        N=N+1;
        int j=0;
        for(int i=0;i<n;i++){
            int x=pow(2,j);
            long long temp=0;
            temp=(((N)/x)/2)*x;
            if((N%x)!=0){
                if((N/x)%2!=0)
                temp+=(N%x);
            }
            ans+=temp;
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends