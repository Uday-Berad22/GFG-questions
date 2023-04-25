//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
        queue<long long > q;
        int i=0;
        int j=k;
        for(int i=0;i<k;i++){
            if(arr[i]<0)
            q.push(arr[i]);
        }
        vector<long long > ans;
       while(j<n){
            if(q.empty())
            ans.push_back(0);
            else{
            ans.push_back(q.front());
             }
           if(arr[i]<0){
               q.pop();
           }
           if(arr[j]<0){
               q.push(arr[j]);
           }
           j++;
           i++;
       } 
       if(q.empty())
            ans.push_back(0);
            else{
            ans.push_back(q.front());
             }
       return ans;
 }