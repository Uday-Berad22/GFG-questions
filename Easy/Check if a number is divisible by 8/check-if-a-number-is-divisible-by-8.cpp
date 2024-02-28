//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int num=0;
        int n=s.size();
        int count=min(n,3);
        int i=s.size()-1;
        int j=1;
        while(count--){
            num=num+((s[i]-'0')*j);
            i--;
            j=j*10;
        }
        return num%8==0 ? 1: -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends