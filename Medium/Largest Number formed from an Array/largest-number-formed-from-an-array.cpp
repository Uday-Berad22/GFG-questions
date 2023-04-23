//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
bool cmp(string a,string b){
    string n=a+b;
    string m=b+a;
    return n>m;
}
class Solution{
public:
	string printLargest(vector<string> &arr) {
	    string s;
	    sort(arr.begin(),arr.end(),cmp);
	    for(int i=0;i<arr.size();i++){
	        s+=arr[i];
	    }
	    return s;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends