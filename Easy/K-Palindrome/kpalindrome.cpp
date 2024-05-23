//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int longestPalindromicSubsequence(vector<vector<int>> &dp,int i,int j,string &str){
       if(j==i){
           return 1;
       }
       if(j<i){
           return 0;
       }
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
       if(str[i]==str[j]){
           return dp[i][j]=2+longestPalindromicSubsequence(dp,i+1,j-1,str);
       } 
       else{
           return dp[i][j]=max(longestPalindromicSubsequence(dp,i+1,j,str),longestPalindromicSubsequence(dp,i,j-1,str));
       }
    }
    int kPalindrome(string str, int n, int k)
    {
        // code here
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return ( n-longestPalindromicSubsequence(dp,0,n-1,str))<=k ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends