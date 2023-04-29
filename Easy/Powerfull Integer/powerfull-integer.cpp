//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// const int N=1e4;
class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        int N=0;
        for(int i=0;i<n;i++){
            N=max(N,intervals[i][1]);
        }
        vector<int> v(N+2,0);
        for(int i=0;i<n;i++){
            v[intervals[i][0]]++;
            v[intervals[i][1]+1]--;
        }
        for(int i=1;i<=N;i++){
            v[i]=v[i]+v[i-1];
        }
        // int m=INT_MIN;
        int ans=-1;
        for(int i=1;i<=N;i++){
            if(v[i]>=k){
                // m=v[i];
                ans=i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends