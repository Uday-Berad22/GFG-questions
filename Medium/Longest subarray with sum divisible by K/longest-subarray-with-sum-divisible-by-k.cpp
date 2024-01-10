//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    vector<int> prefix(n+1,0);
	    unordered_map<int,int> m;
	    int count=0;
	    int ans=0;
	    for(int i=0;i<n;i++){
	        prefix[i+1]=prefix[i]+arr[i];
	        prefix[i+1]=((prefix[i+1]%k)+k)%k;
	        if(prefix[i+1]==0) {
	            ans=max(ans,i+1);
	        }
	        else{
	            if(m.find(prefix[i+1])!=m.end()){
	                ans=max(ans,(i+1-m[prefix[i+1]]));
	                
	            }
	            else{
	                m[prefix[i+1]]=i+1;
	            }
	        }
	        
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends