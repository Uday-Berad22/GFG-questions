//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        unordered_set<int> set;
        for(int i = 0; i < m; i++)
            set.insert(b[i] << 1);
        int sum1 = accumulate(a, a + n, 0L), sum2 = accumulate(b, b + m, 0L);
        int diff = sum2 - sum1;
        if(diff & 1)
            return -1;
        for(int i = 0; i < n; i++)
            if(set.count(diff + (a[i] << 1)))
                return true;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends