//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        // Your code here
        int Xor=0;
        for(int i=31;i>=0;i--){
            if((n>>i)&1){
                Xor=Xor^1;
            }
            else{
                Xor=Xor^0;
            }
            if(Xor==1){
                n=n|(1<<i);
            }
            else{
                if((n>>i)&1){
                    n=n^(1<<i);
                }
            }
        }
        return n;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends