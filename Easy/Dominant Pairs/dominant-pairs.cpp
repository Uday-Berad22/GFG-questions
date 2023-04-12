//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        int j=n/2,i=0;
        int count=0;
        int ans=0;
        int prev=0;
        sort(arr.begin(),arr.begin()+n/2);
        sort(arr.begin()+(n/2),arr.end());
        int pre[n]={0};
        
        while(j<n&&i<n/2){
            if(arr[i]>=5*arr[j]){
                count++;
                j++;
            }
            else{
                prev=prev+count;
                // cout<<i<<endl;
                // cout<<count<<endl;
                // pre[i+1]=pre[i]+count;
                count=0;
                ans=prev+ans;
                i++;
                
            }
        }

        if(count!=0){
             ans=prev+ans+count;
             i++;
        }
        if(i<n/2){
            ans+=(n/2-i)*(n/2);
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
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends