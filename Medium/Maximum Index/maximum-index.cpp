//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        vector<int> v(N,0);
        v[N-1]=A[N-1];
        for(int i=N-2;i>=0;i--){
            v[i]=max(v[i+1],A[i]);
        }
        int ans=0;
        for(int i=0;i<N-1;i++){
            if(v[i+1]>=A[i]){
                for(int j=N-1;j>=i;j--){
                    if(A[j]>=A[i]) { 
                        ans=max(j-i,ans);
                    }
                }
            }
            if(ans>N-i) return ans;
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