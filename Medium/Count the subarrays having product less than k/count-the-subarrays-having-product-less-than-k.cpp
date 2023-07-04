//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
            long long pro=a[0];
            int i=0,j=0;
            int ans=0;
            while(j<n&&i<n){
                if(pro<k){
                i++;
                pro=pro*1LL*a[i];
                if(i>j)
                ans+=((i-j));
                // cout<<i<<" "<<j<<"\n";
                // i++;
                }
                else{
                    pro=pro/a[j];
                    j++;
                }
            }
            // if(pro<k){
            //     // pro=pro*1LL*a[i];
            //     // i--;
            //      if(i>j)
            //     ans+=((i-j));
            //     // i++;
            //     }
            return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends