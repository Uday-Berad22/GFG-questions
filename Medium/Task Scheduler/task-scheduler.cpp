//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int k, vector<char> &tasks) {
        // code here
        int n=N;
        vector<int> m(26,0);
        for(int i=0;i<n;i++){
            m[tasks[i]-'A']++;
        }
        sort(m.begin(),m.end());
        int count=0;
        int ans=0;
        int prefix[27]={0};
        for(int i=m.size()-2;i>=0;i--){
            if(m[25]==m[i]){
             count++;
            }
        }
        return max(N,(m[25]+(m[25]-1)*k+count));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends