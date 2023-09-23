//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>

class Solution{
    public:
    
    int equilibriumPoint(long long a[], int n) {
        long long x=0;
        long long sum=accumulate(a,a+n,x);
        long long prefix=0;
        for(int i=0;i<n;i++){
            sum-=a[i];
            if(prefix==sum){
                return i+1;
            }
            prefix+=a[i];
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends