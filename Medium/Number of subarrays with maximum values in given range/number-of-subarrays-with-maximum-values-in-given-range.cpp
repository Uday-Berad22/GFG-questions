//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        long long nm=0;
        int j=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(a[i]>R){
                j=i+1;
                nm=0;
            }
            else if(a[i]<L){
                ans+=(nm);
            }
            else{
                ans+=(i-j+1);
                nm=i-j+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends