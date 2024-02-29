//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    vector<int> v(32,0);
	    long long ans=0;
	    for(int i=0;i<n;i++){
	        int x=arr[i];
	        for(int j=0;j<32;j++){
	            if((x>>j)&1){
	                v[j]++;
	            }
	       //     else{
	       //         ans+=(2*v[j]);
	       //     }
	        }
	    }
	    for(int i=0;i<n;i++){
	        int x=arr[i];
	        for(int j=0;j<32;j++){
	            if((x>>j)&1){
	               // v[j]++;
	            }
	            else{
	                ans+=(2*v[j]);
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends