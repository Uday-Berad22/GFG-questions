//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool isPrime(int i){
        for(int j=2;j*j<=i;j++){
            if(i%j==0) return false;
        }
        return true;
    }
    int smithNum(int n) {
        // code here
        int num=n;
        unordered_map<int,int> m;
        for(int i=n-1;i>1;i--){
            if(n<i){
                continue;
            }
            if(isPrime(i)){
            while(n%i==0){
                n=n/i;
                m[i]++;
            }
            }
        }
        int val=0;
        for(auto a: m){
            int sum=0;
            int x=a.first;
            while(x>0){
                 sum+=x%10;
                x=x/10;
            }
            val=val+(sum*a.second);
        }
        int sum=0;
        while(num>0){
            sum+=num%10;
            num=num/10;
        }
        return val==sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends