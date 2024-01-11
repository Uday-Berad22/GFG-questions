//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        stack<int> stk;
        int n=s.size();
        for(int i=0;i<n;i++){
            int x=s[i]-'0';
            if(stk.empty()){
                stk.push(x);
            }
            else{
                while(!stk.empty()&&stk.top()>x&&k>0){
                    stk.pop();
                    k--;
                }
                stk.push(x);
            }
        }
        string ans;
        while(stk.size()>0&&k>0){
            int x=stk.top();
            stk.pop();
            // ans.push_back(x+'0');
            k--;
        }
        while(stk.size()>0){
            int x=stk.top();
            stk.pop();
            char c='0'+x;
            ans.push_back(c);
        }
        string fans;
        int j=ans.size()-1;
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]!='0'){
                break;
            }
            else{
                j=i-1;
            }
        }
        for(int i=0;i<=j;i++){
            fans.push_back(ans[i]);
        }
        reverse(fans.begin(),fans.end());
        if(fans.size()==0){
            fans.push_back('0');
        }
        return fans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends