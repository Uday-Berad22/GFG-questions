//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool check(int mid,vector<int > & stalls,int k){
        int last=stalls[0];
        k--;
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last>=mid){
                k--;
                last=stalls[i];
            }
        }
        return k<=0;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low=0;
        int high=stalls[n-1];
        while(high-low>1){
            int mid=(high+low)/2;
            if(check(mid,stalls,k)){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends