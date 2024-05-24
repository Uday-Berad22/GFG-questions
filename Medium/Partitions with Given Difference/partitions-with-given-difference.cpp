//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int M=1e9+7;
  public:
    int rec(int sum,int sumi,int i,int d,vector<int> &arr,int fsum,vector<vector<int>> &dp,vector<int> &suffix,int &req){
        
        if(i>=arr.size()){
            return (fsum-sum==d?1:0);
        }
        if(sum<req){
            return 0;
        }
        if(dp[i][sumi]!=-1){
            return dp[i][sumi];
        }
        
        int a=rec(sum-arr[i],sumi,i+1,d,arr,fsum+arr[i],dp,suffix,req);
        int b=rec(sum,sumi+arr[i],i+1,d,arr,fsum,dp,suffix,req);
        return dp[i][sumi]=(a+b)%M;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        // sort(arr.begin(),arr.end(),greater<int> ());
        int sum=accumulate(arr.begin(),arr.end(),0);
        vector<int> suffix(n+1,0);
        for(int i=n-1;i>=0;i--){
            suffix[i]+=(arr[i]+suffix[i+1]);
        }
        int req=(sum-d)/2;
        if((sum+d)%2){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int> (sum+d+1,-1));
        return rec(sum,0,0,d,arr,0,dp,suffix,req);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends