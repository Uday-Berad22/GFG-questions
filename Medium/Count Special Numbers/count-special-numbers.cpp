//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const int M=1e5+10;
 vector<int>agree(M,0);
class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> a) {
        for(int i=0;i<M;i++){
            agree[i]=0;
        }
        //  if(n==100000&&a[n-1]==99995)
        // cout<<agree[99995];
        if(n==1)
        return 0;
        int N=*max_element(a.begin(),a.end());
        // cout<<N<<endl;
        unordered_map<int,int> m;
        int flag=0;
        for(int i=0;i<n;i++){
            m[a[i]]++;
            if(a[i]==1){
                flag=1;
            }
        }
        if(flag==1){
            if(m[1]>1){
                return n;
            }
            return n-1;
        }
        
        for(int i=2;i<=N;i++){
            if(m[i]>0&&agree[i]==0){
                if(m[i]>1){
                    // cout<<"he"<<endl;
                    agree[i]=1;
                }
                for(int j=2*i;j<=N;j=j+i){
                    agree[j]=1;
                }
            }
        }
        // // sort(a.begin(),a.end(),greater<int>());
        // if(n==100000&&a[n-1]==99995)
        // cout<<agree[99995];
        int count=0;
        for(int i=0;i<n;i++){
            if(agree[a[i]]==1){
                count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends