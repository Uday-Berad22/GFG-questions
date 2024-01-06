//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    int sum=0;
	   
	    for(int i=a;i<=b;i++){
	        int num=i;
	        int temp=0;
	         for(int j=2;j*j<=num;j++){
                  while(num%j==0){
                    temp++;
                   num=num/j;
                 }
            }
	        if(num!=1) temp++;
            sum+=temp;
	    }
	    return sum;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends