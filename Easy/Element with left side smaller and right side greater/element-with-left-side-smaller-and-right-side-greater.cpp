//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    vector<int> suffixMini(n);
    suffixMini[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffixMini[i]=min(arr[i+1],suffixMini[i+1]);
    }
    int prefix=arr[0];
    for(int i=1;i<n-1;i++){
        if(arr[i]>=prefix && arr[i]<=suffixMini[i]){
            return arr[i];
        }
        prefix=max(prefix,arr[i]);
    }
    return -1;
}