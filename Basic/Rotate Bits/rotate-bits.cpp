//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            d=(d%16);
            int a,b;
            int D=d;
            a=0;
            b=(n>>d);
             for(int i=16-D-1;i>=0;i--){
                a=(a<<1);
                if((n>>i)&1){
                    a=a|1;
                }

            }
            for(int i=15;i>=16-D;i--){
                a=(a<<1);
                if((n>>i)&1){
                    a=a|1;
                }
            }
            
            for(int i=0;i<D;i++){
                if((n>>i)&1){
                    b=b|(1<<(16-D+i));
                }
            }
            return {a,b};
            // 10010
            // 100100000
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends