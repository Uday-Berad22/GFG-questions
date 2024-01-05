//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int M=1e9+7;
	int TotalWays(int n)
	{
	    // Code here
	    vector<vector<int>> v(2,vector<int> (n+1));
	    v[0][0]=1;
	    v[1][0]=1;
	    for(int i=1;i<n;i++){
	       v[0][i]=(v[1][i-1]+v[0][i-1])%M;
	       v[1][i]=(v[0][i-1])%M;
	    }
	    int temp=(v[0][n-1]+v[1][n-1])%M;
	    return (temp*1LL*temp)%M;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends