//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
     
        vector<long long > prefix(n,0);
        vector<long long > suffix(n,0);
        prefix[0]=max(a[0],0LL);
        suffix[n-1]=max(a[n-1],0LL);
        long long sum=0;
        for(int i=1;i<n;i++){
           prefix[i]=max(max(prefix[i-1]+a[i],a[i]),0LL) ;
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(max(suffix[i+1]+a[i],a[i]),0LL) ;
        }
        for(int i=0;i<k;i++){
            sum+=a[i];
        }
        int i=0;
        if(k==n) return sum;
        long long maxi=sum;
        for(int j=k;j<n&&(n-i-1>=k);j++){
            sum=sum-a[i];
            sum+=a[j];
            maxi=max(sum+(j+1<n?suffix[j+1]:0LL),max(sum+prefix[i],maxi));
            i++;
            
        }
        return maxi;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends