//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	vector<long long > v(n+1,0);
    	v[0]=1;
    	vector<long long > num={3,5,10};
    	for(int i=1;i<=n;i++){
            if(i-3>=0){
                v[i]+=v[i-3];
            }
    	}
    	for(int i=1;i<=n;i++){
            if(i-5>=0){
                v[i]+=v[i-5];
            }
    	}
    	for(int i=1;i<=n;i++){
            if(i-10>=0){
                v[i]+=v[i-10];
            }
    	}
    	return v[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends