//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // // Code here.
        // int ans=0;
        // int x;
        // int n=nums.size();
        // for(int i=0;i<nums.size();i++){
        //     ans=ans^nums[i];
        // }
        // for(int i=0;i<n;i++){
        //     if(abs(__builtin_popcount(ans)-__builtin_popcount(nums[i]))==1){
        //         x=nums[i];
        //         break;
        //     }
        // }
        // int y=x;
        // for(int i=0;i<n;i++){
        //     y=y^nums[i];
        // }
        vector<int> a;
        // 
        // return a;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto x: m){
            if(x.second==1){
                a.push_back(x.first);
            }
        }
        sort(a.begin(),a.end());
        return a;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends