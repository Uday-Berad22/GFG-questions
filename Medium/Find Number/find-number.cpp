//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int val(int x){
    if(x==0) return 9;
    else if(x==1) return 1;
    else if(x==2) return 3;
    else if(x==3) return 5;
    else return 7;
}
class Solution{
public:
    long long findNumber(long long N){
        long long i=1;
        long long ans=0;
        if(N==1) return 1;
        int last=N%2;
       while(N>0){
           ans=ans+i*1LL*val(N%5);
           i=i*10;
        //   if(N==5||N==0) break;
           if(N%5==0){
               N=(N/5)-1;
            //   last=0;
           }
           else{
               N=N/5;
            //   last=1;
           }
           
       }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends