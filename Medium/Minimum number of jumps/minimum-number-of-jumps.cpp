//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1) return 0;
        int jump=1;
        int target=n;
        target-=arr[0];
        int count=arr[0];
        int j=0;
        if(target<=1) return jump;
        for(int i=1;i<n;){
            int maxi=0;
            while(count--&&i<n){
                if(maxi<=arr[i]+i){
                    j=i;
                    maxi=arr[i]+i;
                    
                }
                i++;
            }
            if(maxi==0) return -1;
            count=maxi-j;
            // cout<<j<<endl;
            jump++;
            target-=maxi;
            if(maxi>=n-1) return jump;
            i=j+1;
        }
        return jump;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends