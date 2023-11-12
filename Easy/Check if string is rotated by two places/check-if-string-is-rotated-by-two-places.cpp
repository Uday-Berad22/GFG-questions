//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int i=2;
        int n=str1.size();
        int j=0;
        int cnt1=0,cnt2=0;
        while(j<n){
            if(str1[i%n]==str2[j]) cnt1++;
            if(str1[j]==str2[i%n]) cnt2++;
            i++;
            j++;
        }
        return (cnt1==n||cnt2==n)?true:false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends