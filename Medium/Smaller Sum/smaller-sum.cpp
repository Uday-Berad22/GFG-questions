//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        
        vector<long long > ans(n,0);
        long long  prefix[n+1]={0};
        vector<int> v=arr;
        sort(arr.begin(),arr.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i]=0;
                prefix[i]=arr[i];
            }
            else{
                if(arr[i]==arr[i-1]){
                    count++;
                }
                else{
                    count=0;
                }
                prefix[i]=prefix[i-1]+arr[i];
                ans[i]=(prefix[i-1]-(arr[i]*count));
                // cout<<"hello"<<endl;
            }
        }
        unordered_map<long long ,long  long > m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]=ans[i];
        }
        for(int i=0;i<n;i++){
            ans[i]=m[v[i]];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends