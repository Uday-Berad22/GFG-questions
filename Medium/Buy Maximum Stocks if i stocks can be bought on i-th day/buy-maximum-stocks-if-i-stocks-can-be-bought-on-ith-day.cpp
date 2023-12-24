//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({price[i],i});
        }
        sort(v.begin(),v.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(k<v[i].first) break;
            int x=min(k/v[i].first,v[i].second+1);
            k=k-(x*v[i].first);
            count+=x;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends