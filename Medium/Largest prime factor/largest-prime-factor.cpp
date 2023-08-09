//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){

        long long  ans=N;
        for(int i=2;i*i<=N;i++){
            if(N>0&&N%i==0)
            ans=i;
            while(N>0&&N%i==0){
                N=N/i;
            }
        }
      if(N>1) return N;
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends