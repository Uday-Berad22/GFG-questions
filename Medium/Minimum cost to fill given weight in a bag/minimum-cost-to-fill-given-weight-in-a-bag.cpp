//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<vector<long long >> dp(n+1,vector<long long > (w+1,INT_MAX));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(cost[i-1]==-1){
                    dp[i][j]=dp[i-1][j];
                }
                else if(i==j){
                    dp[i][j]=min(dp[i-1][j],cost[i-1]*1LL);
                }
                else if(j-i>=0){
                    dp[i][j]=min(dp[i-1][j],cost[i-1]+dp[i][j-i]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][w]>=INT_MAX?-1:dp[n][w];
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends