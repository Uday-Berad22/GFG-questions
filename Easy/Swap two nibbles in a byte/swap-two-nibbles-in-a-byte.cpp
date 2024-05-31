//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        for(int i=0;i<4;i++){
            if((n>>i)&1){
                if((n>>(i+4))&1){
                    
                }
                else{
                     n=n^(1<<i);
                     n=n^(1<<(i+4));
                }
            }
            else{
                if((n>>(i+4))&1){
                    n=n^(1<<i);
                    n=n^(1<<(i+4));
                }
                else{

                }
            }
        }
        return n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends