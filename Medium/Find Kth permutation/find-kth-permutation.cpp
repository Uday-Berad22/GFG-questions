//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void giveMePermutation(vector<string> &ans,string &s,int level,int &flag,int &k){
        if(flag==1) return ;
        if(level==s.size()){
            ans.push_back(s);
            if(ans.size()==k){
                flag=1;
            }
            return ;
        }
        for(int i=level;i<s.size();i++){
            swap(s[level],s[i]);
            if(flag==1) return ;
            giveMePermutation(ans,s,level+1,flag,k);
        }
        if(flag==1) return ;
        for(int i=level;i<s.size()-1;i++){
            swap(s[i],s[i+1]);
        }
    }
    string kthPermutation(int n, int k)
    {
        string s;
        for(int i=1;i<=n;i++){
            s.push_back(char(i+'0'));
        }
        int flag=0;
        vector<string> ans;
        giveMePermutation(ans,s,0,flag,k);
        return ans[k-1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends