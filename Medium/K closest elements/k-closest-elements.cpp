//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int l=lb-1;
        int r=lb;
        vector<int> ans;
        while(k){
            if(l>=0&&r<n){
                while(arr[r]-x==0) r++;
                if(abs(arr[l]-x)>=abs(arr[r]-x) && (arr[r]-x) != 0)
                {
                    ans.push_back(arr[r++]);
                }
                else{
                    ans.push_back(arr[l--]);
                }
                
            }
            else if(l>=0){
                ans.push_back(arr[l--]);
            }
            else{
                while(arr[r]-x==0) r++;
                ans.push_back(arr[r++]);
            }
            k--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends