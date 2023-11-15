//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int M=1e9+7;
class Solution {
  public:
    int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n=s.size();
	    vector<long long > prefix(n+1,0);
	    unordered_map<char,int> m;
	    long long  sum=0;
	    for(int i=1;i<=n;i++){
	        //-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o
	        long long  count=sum;
	        if(m.find(s[i-1])!=m.end()){
	            count=(count-prefix[m[s[i-1]]-1]+M)%M;
	        }
	        else{
	            count++;
	        }
	        m[s[i-1]]=i;
	        sum=(sum+count)%M;
	        prefix[i]=sum;
	       // cout<<sum<<endl;
	    }
	    return (sum+1)%M;
	}
    string betterString(string str1, string str2) {
        // code here                                                ggg
        return distinctSubsequences(str1)>=distinctSubsequences(str2)?str1:str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends