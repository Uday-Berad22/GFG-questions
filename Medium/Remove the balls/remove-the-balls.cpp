//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<=b.second;
    }
    return a.first<b.first;
}
class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int,int> > s;
        vector<pair<int,int>> c;
        for(int i=0;i<N;i++){
            c.push_back({color[i],radius[i]});
        }
        // sort(c.begin(),c.end(),cmp);
        for(int i=0;i<N;i++){
            if(s.empty()){
                s.push(c[i]);
            }
            else if(s.top().first==c[i].first&&s.top().second==c[i].second){
                s.pop();
            }
            else{
                s.push(c[i]);
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends