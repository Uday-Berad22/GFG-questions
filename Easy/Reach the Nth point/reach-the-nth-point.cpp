//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int M=1e9+7;
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    if(n<=1) return 1;
		    int a=1,b=1;
		    int c=1;
		    for(int i=2;i<=n;i++){
		        c=(a+b)%M;
		        a=b;
		        b=c;
		    }
		    return c%M;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends