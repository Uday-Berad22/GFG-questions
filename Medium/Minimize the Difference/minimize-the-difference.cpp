//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<int> maxi1(n+1,INT_MIN),mini1(n+1,INT_MAX),maxi2(n+1,INT_MIN),mini2(n+1,INT_MAX);
        for(int i=1;i<=n;i++){
            maxi1[i]=max(arr[i-1],maxi1[i-1]);
            mini1[i]=min(arr[i-1],mini1[i-1]);
        }
        for(int i=n-1;i>=0;i--){
            maxi2[i]=max(arr[i],maxi2[i+1]);
            mini2[i]=min(arr[i],mini2[i+1]);
        }
        int j=0;
        int ans=INT_MAX;
        for(int i=k;i<=n;i++){
            int mini=INT_MAX;
            int maxi=INT_MIN;
            if(j>0){
              mini=min(mini,mini1[j]);  
              maxi=max(maxi,maxi1[j]);  
            }
            mini=min(mini,mini2[i]);  
            maxi=max(maxi,maxi2[i]); 
            ans=min(maxi-mini,ans);
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends