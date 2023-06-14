//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // 11110

        int end=ceil(log10(n))+2;
        // cout<<end<<endl;
        int ans=0;
        for(int i=0;i<=31;i++){
            int temp=(n+1)/pow(2,i);
            temp=temp/2;
            temp=temp*(pow(2,i));
            if((n>>i)&1){
                temp+=((n+1)%(int)pow(2,i));
            }
            // cout<<temp<<endl;
            ans+=temp;
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends