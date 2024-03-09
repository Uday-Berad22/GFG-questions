//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char myFun(string s,int r,int n){
        if(r==0){
            return s[n-1];
        }
        char Curans=myFun(s,r-1,(n+1)/2);
        if(Curans=='0'  && n%2==0){
            return '1';
        }
        else if(Curans=='0'  && n%2!=0){
            return '0';
        }
        else if(Curans=='1'  && n%2!=0){
            return '1';
        }
        return '0';
    }
    char nthCharacter(string s, int r, int n) {
        //code here
        // if(r>s.size()){
        //     return '0';
        // }
        return myFun(s,r,n+1);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends