//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool check(vector<int> &m1,vector<int> &m2){
        for(int i=0;i<m1.size();i++){
            if(m1[i]!=m2[i]) return false;
        }
        return true;
    }
	int search(string pat, string txt) {
	    // code here
	    int count=0;
	    if(pat.size()>txt.size()) return 0;
	    vector<int>  m1(26,0),m2(26,0);
	    
	    for(int i=0;i<pat.size();i++){
	        m1[pat[i]-'a']++;
	        m2[txt[i]-'a']++;
	    }
	    if(check(m1,m2)){
	        count++;
	    }
	    int j=0;
	    for(int i=pat.size();i<txt.size();i++){
	        m2[txt[j]-'a']--;
	        m2[txt[i]-'a']++;
	        if(check(m1,m2)){
	            count++;
	        }
	        j++;
	    }
	    return count;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends