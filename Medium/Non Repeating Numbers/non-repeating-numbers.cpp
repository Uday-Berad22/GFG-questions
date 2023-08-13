//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xor_of_two_nums_of_ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xor_of_two_nums_of_ans=xor_of_two_nums_of_ans^nums[i];
        }
        int set_bits=0;
        int unset_bits=0;
        int j=0;
        for(int i=0;i<32;i++){
            if(1&(xor_of_two_nums_of_ans>>i)){
                j=i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(1&(nums[i]>>j)){
                set_bits=set_bits^nums[i];
            }
            else{
                unset_bits=unset_bits^nums[i];
            }
        }
        vector<int> v={set_bits,unset_bits};
        sort(v.begin(),v.end());
        return v;
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