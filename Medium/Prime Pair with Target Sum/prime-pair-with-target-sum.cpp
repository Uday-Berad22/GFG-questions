//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

bool isPrime[1000002];
class Solution {
  public:
    
    vector<int> sOfE(int n){
        unordered_map<int,int> m;
        vector<int> ans={-1,-1};
        for(int i=2;i<=n;i++){
            if(isPrime[i]==true){
                m[i]++;
                if(m[n-i]>0){
                    ans= {n-i,i};
                }
                for(long long  j=i*1LL*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        return ans;
    }
    vector<int> getPrimes(int n) {
        // code here
        memset(isPrime,1,n+1);
        isPrime[0]=isPrime[1]=false;
        return sOfE(n);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends