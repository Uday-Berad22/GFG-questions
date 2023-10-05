//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    long long int fun(string s,int k){
        int m[26]={0};
    	long long int count=0;
    	int cnt=0;
    	int j=0;
    	for(int i=0;i<s.size();i++){
    	    if(m[s[i]-'a']==0) cnt++;
    	    m[s[i]-'a']++;
    	    while(cnt>k&&j<i){
    	        m[s[j]-'a']--;
    	        if(m[s[j]-'a']==0) cnt--;
    	        j++;
    	    }
    	    if(cnt<=k){
    	        count+=(i-j+1);
    	    }
    	}
    	return count;
    }
    long long int substrCount (string s, int k) {
        // int n=nums.size();
        // int cnt=0;
        // int ans=0;
        // int prefix=0;
        // int j=0;
        // unordered_map<char,int> m;
        // for(int i=0;i<n;i++){
        //     if(m[nums[i]]==0){
        //         cnt++;
        //     }
        //     m[nums[i]]++;
        //     if(cnt>k){
        //         prefix=0;
        //         cnt--;
        //         m[nums[j]]--;
        //         j++;
        //     }
        //     while(m[nums[j]]>1){
        //         prefix++;
        //         m[nums[j]]--;
        //         j++;

        //     }
        //     if(cnt==k){
        //         ans=ans+(prefix)+1;
        //     }
        // }
        // return ans;
        return fun(s,k)-fun(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends