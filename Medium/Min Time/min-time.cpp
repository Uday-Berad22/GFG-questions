//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long help(int index,int pos,vector<int> &a,vector<int> &b,vector<vector<long long > > &dp,int indicator){
        if(index==a.size()){
              return abs(pos);
        }
        if(dp[index][indicator]!=-1){
            return dp[index][indicator];
        }
        long long x=abs(pos-a[index])+abs(a[index]-b[index])+abs(help(index+1,b[index],a,b,dp,0));
        long long y=abs(pos-b[index])+abs(a[index]-b[index])+abs(help(index+1,a[index],a,b,dp,1));
        
        return dp[index][indicator]=min(x,y);
    }
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        // code here
        vector<int> a,b;
        vector<int>  l(100001,INT_MAX);
        vector<int> r(100001,INT_MIN);
        for(int i=0;i<n;i++){
            l[types[i]]=min(l[types[i]],locations[i]);
            r[types[i]]=max(r[types[i]],locations[i]);
        }
        for(int i=0;i<100001;i++){
            if(l[i]==INT_MAX||r[i]==INT_MIN){
                continue;
            }
            a.push_back(l[i]);
            b.push_back(r[i]);
        }
        vector<vector<long long >> dp(a.size(),vector<long long > (2,-1));
        long long ans=help(0,0,a,b,dp,0);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends