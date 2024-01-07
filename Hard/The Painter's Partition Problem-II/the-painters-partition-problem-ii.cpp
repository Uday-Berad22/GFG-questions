//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool check(int arr[],long long  mid,int N,int k){
        long long sum=0;
        long long  count=0;
        for(int i=0;i<N;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                count++;
                sum=arr[i];
            }
            if(arr[i]>mid) return false;
        }
        count++;
        return count<=k;
    }
    long long  minTime(int arr[] ,int N, int k) {
        // code here
        
        long long  low=0;
        long long high=1e9;
        while(high-low>1){
            long long  mid=(high+low)/2;
            if(check(arr,mid,N,k)){
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