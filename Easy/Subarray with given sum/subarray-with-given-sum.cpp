//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>a, int n, long long s)
    {
        // Your code 
        // long long sum=*accumulate(arr.begin(),arr.end());
        long long sum=0;
        for(int i=0;i<a.size();i++){
            sum+=a[i];
        }
        int i=0,j=a.size()-1;
        while(i<n&&i>=0&&j<n&&j>=0){
            // cout<<sum<<" "<<i<<endl;
            if(sum==s){
                return {(i+1),(j+1)};
            }
            if(sum>s){
                if(sum-a[j]>=s){
                    // cout<<sum-a[j]<<"**"<<a[j]<<" "<<j<<endl;
                sum=sum-a[j];
                j--;
                }
                else{
                    sum-=a[i];
                    i++;
                }
                
            }
            else if(sum<s){
                j++;
                sum+=a[j];
            }
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