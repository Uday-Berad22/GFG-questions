//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        // Code here
        int m=INT_MAX;
        if(arr.size()<1e4)
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            if(arr[i+1]!=arr[i])
            m=min(m,abs(arr[i+1]-arr[i]));
        }
        return m;
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
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}
// } Driver Code Ends