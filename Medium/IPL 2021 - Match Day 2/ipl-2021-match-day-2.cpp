//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        map<int,int> m;
        for(int i=0;i<k;i++){
            m[arr[i]]++;
        }
        int i=0;
        int j=k;
        // cout<<m[1999]<<endl;
        while(j<n){
            auto a=m.begin();
            int x=a->first;
            for(auto a=--m.end();a!=m.begin();a--){
                if(a->second!=0){
                    x=a->first;
                    break;
                }
            }
            ans.push_back(x);
            m[arr[i]]--;
            m[arr[j]]++;
            // cout<<m[1999]<<endl;
            // cout<<arr[i]<<" "<<ans[i]<<endl;
            // cout<<a->first<<endl;
            i++;
            j++;
            
        }
        // cout<<m[1999]<<endl;
       auto a=m.begin();
            int x=a->first;
            for(auto a=--m.end();a!=m.begin();a--){
                if(a->second!=0){
                    x=a->first;
                    break;
                }
            }
            ans.push_back(x);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends