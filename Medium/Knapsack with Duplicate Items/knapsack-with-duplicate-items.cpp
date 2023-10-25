//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<int> dp;
public:
    int recurssion(vector<pair<int,int>> &v,int sum,int profit,int i,int W){
        int N=v.size();
        if(dp[W-sum]!=-1) return dp[W-sum];
        int ans=0;
        for(int j=0;j<N;j++){
            if(sum+v[j].first<=W){
               ans=max(recurssion(v,sum+v[j].first,profit+v[j].second,j,W)+v[j].second,ans); 
            }
        }
        return dp[W-sum]=ans;
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<pair<int,int>> v;
        dp.assign(W+1,-1);
        for(int i=0;i<N;i++) v.push_back({wt[i],val[i]});
        sort(v.begin(),v.end());
        return recurssion(v,0,0,0,W);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends