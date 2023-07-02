//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int A[], int N) {
	    // code here
	    vector<long long > a(32,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<32;j++){
                if((A[i]>>j)&1){
                    a[j]++;
                }
            }
        }
        long long  count=0;
         for(int i=0;i<N;i++){
            for(int j=0;j<32;j++){
                if(((A[i]>>j)&1)==0&&a[j]!=0){
                    count+=a[j];
                }
            }
        }
        return 2*count;
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