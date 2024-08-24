//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int rec(int i,int W,vector<int> &wt,vector<int> &val, vector<vector<int>> &dp){
        int n=wt.size();
        //base condition
        if(i==n || W<=0){
            return 0;
        }
        
        
        //dp 
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        
        //not take
        
        int a=rec(i+1,W,wt,val,dp);
        
        //take 

        int b=0;
        if(W-wt[i]>=0)
            b=rec(i+1,W-wt[i],wt,val,dp)+val[i];

        
        
        //store in dp and return 
        return dp[i][W]=max(a,b);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        vector<vector<int>> dp(wt.size()+1,vector<int> (W+1,-1));
        return rec(0,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends