//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
           if(nums.size()%2) return false;
        unordered_map<int,int>mp;
        int t=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]%k)!=mp.end()){
                t++;
                mp.erase(nums[i]%k);
                continue;
            }
            if(mp.find(k-nums[i]%k)!=mp.end()){
                t++;
                mp.erase(k-nums[i]%k);
                continue;
            }
            mp[nums[i]%k]++;
        }
        return nums.size()/2==t;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends