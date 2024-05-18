//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here
        int maxi=-1;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(i+1<n && a[i]!=a[i+1])
                maxi=max(a[i],maxi);
            if(i==n-1){
                if(i-1<0) maxi=max(a[i],maxi);
                else{
                    if(a[i]!=a[i-1]){
                        maxi=max(a[i],maxi);
                    }
                }
            }
        }
        return maxi;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends