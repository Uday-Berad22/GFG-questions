//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
     vector<string> ans;
    public:
    //Complete this function
    void permutations_my(string &s,int level){
        if(level==s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=level;i<s.size();i++){
            swap(s[i],s[level]);
            permutations_my(s,level+1);
        }
        for(int i=level;i<s.size()-1;i++){
            swap(s[i],s[i+1]);
        }
    }
    vector<string> permutation(string s)
    {
        sort(s.begin(),s.end());
        permutations_my(s,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends