//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long> prevSmaller,nextSmaller;
        vector<long long> v(n),v2(n);
        v[0]=0;
        prevSmaller.push(0);
        int j=n-1;
        v2[j]=n-1;
        nextSmaller.push(n-1);
        j--;
        for(int i=1;i<n;i++){
            while(!prevSmaller.empty() && arr[prevSmaller.top()]>=arr[i]){
                prevSmaller.pop();
            }
            if(prevSmaller.empty()){
                v[i]=0;
            }
            else{
                v[i]=prevSmaller.top()+1;
            }
            prevSmaller.push(i);
            
            while(!nextSmaller.empty() && arr[nextSmaller.top()]>=arr[j]){
                nextSmaller.pop();
            }
            if(nextSmaller.empty()){
                v2[j]=n-1;
            }
            else{
                v2[j]=nextSmaller.top()-1;
            }
            nextSmaller.push(j);
            j--;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            v2[i]= v2[i]-v[i]+1;
            ans=max(ans,arr[i]*v2[i]);
        }
        
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends