//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string s){
        if(s.size()==1||s[1]>=s[0]){
            string ans;
            ans.push_back(s[0]);
            ans.push_back(s[0]);
            return ans;
        }
        else 
        {
            string ans;
            ans.push_back(s[0]);
            int i=0;
            int n=s.size();
            while(i<n-1&&s[i+1]<=s[i]){
                ans.push_back(s[i+1]);
                i++;
            }
            string t=ans;
            reverse(t.begin(),t.end());
            ans=ans+t;
            // ans.push_back(s[0]);
            // ans.push_back(s[1]);
            // ans.push_back(s[1]);
            // ans.push_back(s[0]);
            return ans;
        }
        return {s[0]};
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends