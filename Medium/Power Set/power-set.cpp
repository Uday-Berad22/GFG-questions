//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void rec(string &s ,int i,vector<string> &ans,string &temp){
	        int n=s.size();
	        if(i>=n){
	            if(temp.size())
	            ans.push_back(temp);
	            return;
	        }
	        
	        // not take
	        rec(s,i+1,ans,temp);
	        //take
	        temp.push_back(s[i]);
	        rec(s,i+1,ans,temp);
	        temp.pop_back();
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string temp="";
		    rec(s,0,ans,temp);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends