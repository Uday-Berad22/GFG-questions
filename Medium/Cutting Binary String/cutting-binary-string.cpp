//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int pow_of_5(long long  val){
        if(val==0) return 0;
    if(val==1) return 1;
    long long  pow=1;
    while(pow<val){
        pow=pow*5;
    }
    if(pow==val) return 1;
    return 0;
}
int cuts(string s){
      int n=s.size();
      int dp[n+1];
      dp[0]=0;
      for(int i=1;i<=n;i++){
        int j=i-1;
        if(s[j]=='0') dp[i]=-1;
        else{
            dp[i]=-1;
            int cur_ans=INT_MAX;
            long long val=0;
            for(int k=0;k<=j;k++){
                if(s[j-k]!='0'){
                val=val+(1<<k);
                if(pow_of_5(val)&&dp[j-k]!=-1){
                    cur_ans=min(cur_ans,1+dp[j-k]);
                }
               }
            }
            if(cur_ans!=INT_MAX){
                dp[i]=cur_ans;
            }
        }
      }
      return dp[n];
}
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends