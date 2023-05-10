//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int j=-1;
        int n=s.size(),flag=0;
        for(int i=0;i<n/2;i++){
            if(s[i]!='?'&&j==-1){
                    j=i;
                }
                 if(s[n-i-1]!='?'&&j==-1){
                    j=n-i-1;
                }
            if((s[i]=='?'||s[n-i-1]=='?')||(s[i]==s[n-i-1])){
                // if(s[i]=='?')
                if(s[i]!='?'&&j==-1){
                    j=i;
                }
                continue;
            }
            else{
                flag=1;
                break;
            }
        }
        // cout<<j<<endl;
        if(flag==1){
            return -1;
        }
        int count=0;
        if(s[0]=='?'){
            s[0]=s[n-1];
            if(s[0]=='?'){
                s[0]=s[j];
                s[n-1]=s[j];
            }
        }
        for(int i=1;i<n;i++){
            if(s[i]=='?'||s[n-1-i]=='?'){
            char c=s[i-1];
           if(s[i]=='?'&&s[n-1-i]=='?'){
            s[i]=s[n-i-1]=c;
            }
            else if(s[i]=='?')
            s[i]=s[n-i-1];
            else 
            s[n-i-1]=s[i];
        }
        }
        for(int i=0;i<n-1;i++){
            count=count+abs(int(s[i]-s[i+1]));
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends