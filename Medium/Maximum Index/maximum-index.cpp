//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int> v1(n),v2(n);
        v1[0]=a[0];
        for(int i=1;i<n;i++){
            v1[i]=min(v1[i-1],a[i]);
        }
        v2[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            v2[i]=max(v2[i+1],a[i]);
        }
        int i=0;
        int j=1;
        int ans=0;
        for(int i=0;i<n && j<n;i++){
            while(j<n && v2[j]>=v1[i]){
                ans=max(ans,j-i);
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends