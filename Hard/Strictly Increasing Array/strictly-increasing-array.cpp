//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int LIS(vector<int> &nums){
        int n=nums.size();
        vector<int> dp(n+1,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(nums[j]<nums[i] && ((i-j-1)<(nums[i]-nums[j]))){
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i]+=1;
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
    int min_operations(vector<int>& nums) {
        // Code here
        return nums.size()-LIS(nums);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends