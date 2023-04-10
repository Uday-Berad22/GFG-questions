//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
/*
class Solution {
  public:
    int maxIntersections(vector<vector<int>> v, int n) 
        vector<pair<int,int> > a;
        for(auto x: v){
            a.push_back({x[0],x[1]});
        }
        sort(a.begin(),a.end(),cmp);
        int min=a[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(min>=a[i][0]){
                min=min(a[i][1],min);
                count++;
            }
        }
        return count;
    }
};
*/
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<=b.second;
    }
    return a.first<b.first;
}
class Solution {
  public:
    int maxIntersections(vector<vector<int>> v, int n) {
      map<int,int>  mp;
      for(auto a: v){
          int s=a[0],e=a[1];
          mp[s]++;
          mp[e+1]--;
      }
      int sum=0,ans=0;
      for(auto a: mp){
          sum+=a.second;
          ans=max(ans,sum);
      }
    //   cout<<sum<<endl;
      return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends