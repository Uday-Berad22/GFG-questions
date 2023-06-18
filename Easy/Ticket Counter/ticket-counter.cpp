//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int k) {
        // code here
        vector<int> v;
        for(int i=0;i<=N+1;i++){
            v.push_back(i);
        }
        int i,j;
        i=0;
        j=N+1;
        int x=1;
        int count=0;
        while(count<N){
            
            if(count+k>N){
                break;
            }
            if(x%2!=0){
                i=i+k;
            }
            else{
                j=j-k;
            }
            count=count+k;
            x++;
        }
        if(count<N){
            if(x%2!=0){
                return j-1;
            }
            else{
                return i+1;
            }
        }
        else{
            if(x%2!=0){
                return j;
            }
            else{
                return i;
            }
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends