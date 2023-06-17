//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int square(int n){
    int  square_of_number;
    square_of_number= (exp(log(n)+log(n)))+0.00001;
    // cout<<<<endl;
    return square_of_number;
}
    vector<int> nearestPerfectSquare(int N) {
        // code here
        int x=(sqrt(N));
        int y=ceil(sqrt(N));
        int ans=square(x);
        int ans2=square(y);
        if(abs(ans-N)<abs(ans2-N)){
            return {ans,abs(ans-N)};
        }
        return {ans2,abs(ans2-N)};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.nearestPerfectSquare(N);
        cout << ans[0] << " " << ans[1] << "\n";
    }
}
// } Driver Code Ends