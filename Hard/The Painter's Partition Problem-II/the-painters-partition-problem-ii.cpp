//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
#define ll long long 
class Solution
{
  public:
    bool check(ll mid,int arr[],int k,int n){
        ll sum=0;
        int count=1;
        for(int i=0;i<n;i++){
            if(arr[i]>mid){
                return false;
            }
            if(sum+arr[i]>mid){
                count++;
                sum=0;
            }
            sum+=arr[i];
        }
        return count<=k;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        ll low=0;
        ll high=1e18;
        while(high-low>1){
            ll mid=low+(high-low)/2;
            if(check(mid,arr,k,n)){
                high=mid;
            }
            else{
                low=mid;
            }
        }
        return high;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends