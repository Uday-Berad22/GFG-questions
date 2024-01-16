//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int rec(int i,int count,int m,int n){
        if(count==n){
            return 1;
        }
        if(i>m) return 0;
        return rec(i+1,count,m,n)+rec(2*i,count+1,m,n);
    }
    int numberSequence(int m, int n){
        // code here
        return rec(1,0,m,n);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends