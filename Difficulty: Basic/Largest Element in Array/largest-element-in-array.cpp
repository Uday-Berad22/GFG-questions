//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maxi=0;
        auto fun=[&arr,&maxi](int i){
            maxi=max(maxi,arr[i]);
        };
        int n=arr.size();
        for(int i=0;i<n;i++){
            fun(i);
        }
        return maxi;   
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.largest(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends