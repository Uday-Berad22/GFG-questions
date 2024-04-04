//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int M=1e9+7;
class Solution
{
    public:
    
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        long long ans=0;
        long long val=0;
        for(int i=0;i<s.size();i++){
            int cn=s[i]-'0';
            val=(val*10+(cn*(i+1)))%M;
            ans=(ans+val)%M;
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends