//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        vector<int> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({A[N-1]+B[N-1],{N-1,N-1}});
        ans.push_back(A[N-1]+B[N-1]);
        map<pair<int,int>,bool> m;
       while(ans.size()<K){
                auto p=pq.top();
                pq.pop();
                int sum=p.first;
                int x=p.second.first;
                int y=p.second.second;
                if(m[{x-1,y}]!=true)
               { pq.push({sum-A[x]+A[x-1],{x-1,y}});m[{x-1,y}]=true;}
               if(m[{x,y-1}]!=true)
                {pq.push({sum-B[y]+B[y-1],{x,y-1}});m[{x,y-1}]=true;}
                ans.push_back(pq.top().first);
                // cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.first<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends