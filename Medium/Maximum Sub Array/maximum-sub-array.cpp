//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<int> maxi(3,0),ans;
	    int sum=0;
	    int last=-1;
	    for(int i=0;i<n;i++){
	        if(a[i]<0){
	            last=i;
	            sum=0;
	        }
	        else{
	            sum+=a[i];
	        }
	        if(sum>maxi[0])
	        {
	            maxi[0]=sum;
	            maxi[1]=i-last;
	            maxi[2]=last;
	        }
	        else if(sum==maxi[0]){
	            maxi[0]=sum;
	            if(maxi[1]<i-last){
	              maxi[1]=i-last;
	              maxi[2]=last;
	            }
	        }
	    }
	    if(maxi[1]==0) return {-1};
	   // cout<<maxi[0]<<" "<<maxi[1]<<" "<<maxi[2]<<endl;
	    for(int i=0;i<maxi[1];i++){
	        ans.push_back(a[i+maxi[2]+1]);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends