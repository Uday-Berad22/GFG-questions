//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans=0;
        int flag=1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-'){
                if(i!=0) return -1;
                flag=-1;
                continue;
            }
            if(s[i]>='0'&&s[i]<='9'){
                ans=ans*10+(s[i]-'0');
            }
            else{
                return -1;
            }
        }
        return ans*flag;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends