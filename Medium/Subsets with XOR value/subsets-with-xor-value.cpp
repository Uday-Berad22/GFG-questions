//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int rec(vector<int> & arr,int k,int tillXor,int i){
        int n=arr.size();
        if(i==n) {
            if(tillXor==k)
            return 1;
            return 0;
        };
        //take 
        int count=rec(arr,k,tillXor^arr[i],i+1);
        //not take 
        count+=rec(arr,k,tillXor,i+1);
        return count;
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        return rec(arr,K,0,0);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends