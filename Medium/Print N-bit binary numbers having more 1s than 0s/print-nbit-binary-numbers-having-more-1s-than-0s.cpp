//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void rec(string &temp,int i,int n,int one,int zero,vector<string> &ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back('1');
        rec(temp,i+1,n,one+1,zero,ans);
        temp.pop_back();
        if(one>zero){
            temp.push_back('0');
            rec(temp,i+1,n,one,zero+1,ans);
            temp.pop_back();
        }
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    int one=0;
	    string temp="";
	    int zero=0;
	    rec(temp,0,n,one,zero,ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends