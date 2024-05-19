//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int val=arr[0];
        for(int i=0;i<n;i++){
            if(abs(k-arr[i])<abs(val-k)){
                val=arr[i];
            }
            else if(abs(k-arr[i])==abs(val-k)&& arr[i]>val){
                val=arr[i];
            }
        }
        return val;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends