//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char s[], int n)
{
    //code here
    vector<vector<bool>> dp(n,vector<bool> (n,false));
    for(int i=0;i<n;i++){
        int r=0,c=i;
        while(r<n&&c<n){
            if(i==0){
                dp[r][c]=true;
            }
            else if(i==1){
                if(s[r]==s[c]){
                    dp[r][c]=true;
                }
            }
            else{
                if(s[r]==s[c]){
                    dp[r][c]=dp[r+1][c-1];
                }
            }
            r++;
            c++;
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(dp[i][j]){
                count++;
            }
           
        }
    }
    return count;
    
}