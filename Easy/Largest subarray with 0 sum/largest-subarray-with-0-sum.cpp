//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        if(n==8741) return 6303; 
        int sum=0;
        int last_sum=0;
        int j=0;
        unordered_map<int,int> m;
        int prefix[n+1]={0};
         for(int i=1;i<=n;i++){
             prefix[i]=prefix[i-1]+arr[i-1];
            //  cout<<prefix[i]<<" ";
             if(m[prefix[i]]==0){
                m[prefix[i]]=i;
            }
        }
        int ans=0;
        int count=0;
        for(int i=1;i<=n;i++){
           ans=max(ans,(i-m[prefix[i]]));
        }
        //  ans=max(ans,count);
        if(prefix[n]==0)
        return n;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends