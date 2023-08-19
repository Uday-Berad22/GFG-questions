//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int low=-1;
	    int high=n;
	    while(high-low>1){
            int mid=(low+high)/2;
            if(arr[mid]<x){
                low=mid;
            }
            else{
                high=mid;
            }
	    }
	    int k=high;
	    low=-1;
	    high=n;
	    while(high-low>1){
            int mid=(low+high)/2;
            if(arr[mid]<=x){
                low=mid;
            }
            else{
                high=mid;
            }
	    }
	    
	    return low-k+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends