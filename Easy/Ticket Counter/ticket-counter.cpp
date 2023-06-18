//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int k) {
        deque<int> dq;
        for(int i=1;i<=N;i++){
            dq.push_back(i);
        }
        int i=1;
        int last;
        while(!dq.empty()){
            if(i%2!=0){
                int temp=k;
                while(temp>0&&dq.size()>0){
                     last=dq.front();
                    dq.pop_front();
                    temp--;
                }
                
            }
            else{
                int temp=k;
                while(temp>0&&dq.size()>0){
                     last=dq.back();
                    dq.pop_back();
                    temp--;
                }
                
            }
            i++;
        }
        return last;
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