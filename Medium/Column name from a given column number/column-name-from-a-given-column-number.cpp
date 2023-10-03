//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int c)
    {
         unordered_map<char,long long > m;
        for(char c='A';c<='Z';c++){
            m[(c-'A'+1)]=c;
        }
        string ans="";
        long long  rem=0;
        while(c>0){
            if(c%26==0){
            c=c-1;
            rem+=1;
           }
            rem=rem+(c%26);
            c=c/26;
            ans.push_back(m[rem]);
            rem=0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends