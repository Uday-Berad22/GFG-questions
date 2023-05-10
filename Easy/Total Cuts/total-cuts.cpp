//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int k,vector<int> &A){
        // Code here
        // multiset<int> msn,msp;
        int mi[N];
        int n=N;
        mi[n-1]=A[n-1];
        for(int i=n-2;i>=0;i--){
            mi[i]=min(A[i],mi[i+1]);
        }
        int count=0;
        int ma=INT_MIN;
        for(int i=0;i<N-1;i++){
            ma=max(ma,A[i]);
            if(ma+mi[i+1]>=k){
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends