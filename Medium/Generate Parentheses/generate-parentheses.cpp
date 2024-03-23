//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void fun(vector<string> &ans,int o,int c,string &temp,int i,int n){
        if(i>=2*n){
            ans.push_back(temp);
            return;
        }
        if(o<n){
            temp.push_back('(');
            fun(ans,o+1,c,temp,i+1,n);
            temp.pop_back();
        }
        if(o>c){
            temp.push_back(')');
            fun(ans,o,c+1,temp,i+1,n);
            temp.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        string temp="";
        vector<string> ans;
        fun(ans,0,0,temp,0,n);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends