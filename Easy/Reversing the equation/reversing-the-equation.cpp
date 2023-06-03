//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string num,ans;
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'){
                    reverse(num.begin(),num.end());
                    ans+=num;
                    ans.push_back(s[i]);
                    num="";
                }
                else{
                    num.push_back(s[i]);
                }
            }
            reverse(num.begin(),num.end());
            ans+=num;
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends