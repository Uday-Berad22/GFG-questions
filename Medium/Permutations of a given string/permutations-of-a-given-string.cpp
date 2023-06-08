//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void giveMePermutation(vector<string> &ans,string &s,int level,unordered_map<string,int> &m){
  
        if(level==s.size()){
            if(m[s]==0)
            ans.push_back(s);
           m[s]++;
            return ;
        }
        for(int i=level;i<s.size();i++){
            swap(s[level],s[i]);
           
            giveMePermutation(ans,s,level+1,m);
        }
        for(int i=level;i<s.size()-1;i++){
            swap(s[i],s[i+1]);
        }
    }

		vector<string>find_permutation(string s)
		{
		    sort(s.begin(),s.end());
		 unordered_map<string,int> m; 
        vector<string> ans;
        giveMePermutation(ans,s,0,m);
        return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends