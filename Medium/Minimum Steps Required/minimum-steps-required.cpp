//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string s) {
    // Write your code here.
    int ca=0,cb=0;
    int flag;
    if(s[0]=='a'){
        // ca++;
        flag=1;
    }
    if(s[0]=='b'){
        // cb++;
         flag=0;
    }
    int count=0;
    
    for(int i=1;i<s.size();i++){
        if(s[i]=='a'){
            if(flag==0){
                cb++;
                flag=1;
            }
        }
        else{
            if(flag==1){
                ca++;
                flag=0;
            }
        }
    }
    if(flag==1){
        ca++;
    }
    else{
        cb++;
    }
    return min(ca,cb)+1;
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends