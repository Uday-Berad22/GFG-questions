//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long k)
    {
        if(k==0)return {-1};
       long long sum=0;
       int i=0,j=0;
       int count=0;
       while(i<n||j<=i){
           if(sum==k){
               return {j+1,i};
           }
           else if(sum>k){
               sum-=arr[j];
               j++;
           }
           else if(i<n){
               sum+=arr[i];
              i++;
           }
           else{
               break;
           }
        //   cout<<i<<" "<<j<<" "<<sum<<endl;
        //   count++;
        //   if(count>=1e5+10) return {1,2};
       }
        if(sum==k){
            return {j+1,i};
        }
       return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends