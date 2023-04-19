//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string s, int x){
        int a[N+1]={0};
        for(int i=0;i<=N;i++){
            a[i]=0;
        }
        for(int i=0;i<N;i++){
            if(s[i]=='1'){
            if((i-x)<0){
                a[0]+=1;
                if(i+x+1<=N)
                a[i+x+1]-=1;
            }
            else{
                a[i-x]+=1;
                if(i+x+1<=N)
                a[i+x+1]-=1;
            }
            }
        }
        int flag=0;
        for(int i=1;i<=N;i++){
            a[i]=a[i]+a[i-1];
            if(a[i-1]==0){
                flag=1;
                break;
            }
        }
        if(flag==1){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends