//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        int k=0;
        int j=31;
        for(int i=0;i<16;i++){
            int b1= (x>>j)&1;
            int b2=((x>>k))&1;
            if(b1==1){
                if(b2==0){
                    x=x^(1LL<<j);
                    x=x^(1LL<<k);
                }
            }
            else{
                if(b2==1){
                    x=x^(1LL<<j);
                    x=x^(1LL<<k);
                }
            }
            k++;
            j--;
        }
        // 10100000000000000000000000000000

        return x;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends