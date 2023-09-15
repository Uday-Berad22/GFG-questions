//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool fun(int i,int Taken,int NotTaken,int N,int arr[],vector<vector<int>> &dp){
        if(i==N) {
            if(Taken ==NotTaken) return true;
            return false;
        }
        if(dp[i][Taken]!=-1) return dp[i][Taken];
        return dp[i][Taken]=fun(i+1,Taken,NotTaken+arr[i],N,arr,dp)||fun(i+1,Taken+arr[i],NotTaken,N,arr,dp);
    }
    int equalPartition(int N, int arr[])
    {
        int sum=accumulate(arr,arr+N,0);
        vector<vector<int>> dp(N+1,vector<int> (sum+1,-1));
        return fun(0,0,0,N,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends