//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const long long  M=1003;
class Solution{
    string s;
    vector<vector<vector<int>>> dp;
public: 
    int rec(int si,int ei,int isTrue){
        if(si>ei){
            return 0;
        }
        if(si==ei){
            if(s[si]=='T' && isTrue){
                return 1;
            }
            if(s[si]=='F' && !isTrue){
                return 1;
            }
            return 0;
        }
        if(dp[si][ei][isTrue]!=-1) return dp[si][ei][isTrue];
        long long count=0;
        for(int i=si+1;i<ei;i+=2){
           long long lT=rec(si,i-1,1),
                lF=rec(si,i-1,0),
                rT= rec(i+1,ei,1),
                rF= rec(i+1,ei,0);
            if(s[i]=='&')//&
            {
                if(isTrue){
                    count+=lT * rT;
                } 
                else{
                    count+=((lF * rT)+(lT*rF)+(lF*rF));
                }
            }
            else if(s[i]=='|')
            {
                if(isTrue){
                     count+=((lF * rT)+(lT*rF)+(lT*rT));
                } 
                else{
                   
                    count+=(lF * rF);
                }
            }
            else
            {
                if(isTrue){
                     count+=((lF * rT)+(lT*rF));
                } 
                else{
                   
                    count+=((lF * rF)+(lT*rT));
                }
            }
        }
        return dp[si][ei][isTrue]=count%M;
    }
    int countWays(int n, string temp){
        s=temp;
        dp.assign(n+1,vector<vector<int>> (n+1,vector<int> (2,-1)));
        return rec(0,n-1,1);
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends