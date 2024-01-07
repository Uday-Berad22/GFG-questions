//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int arr[],long long  mid,int N,int k){
        long long sum=0;
        int count=0;
        for(int i=0;i<N;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                count++;
                sum=arr[i];
            }
        }
        count++;
        return count<=k;
    }
    int splitArray(int arr[] ,int N, int k) {
        // code here
        
        long long  low=*max_element(arr,arr+N)-1;
        long long high=accumulate(arr,arr+N,0)+1;
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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends