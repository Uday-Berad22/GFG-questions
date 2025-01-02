//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<int> pre(n+1,0);
        unordered_map<int,int> m;
        m[0]++;
        int ans=0;
        for(int i=0;i<n;i++){
            pre[i+1]=(pre[i]+arr[i]);
            ans+=(m[pre[i+1]-k]);
            m[pre[i+1]]++;
        }
        return ans;
    }   
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends