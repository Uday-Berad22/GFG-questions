//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      long long  count=n*1LL*n;
      vector<int> s1(n+1,0);
      vector<int> s2(n+1,0);
      int r1=0;
      int c1=0;
      vector<long long> ans;
      for(int i=0;i<k;i++){
          if(s1[arr[i][0]-1]==0){
            s1[arr[i][0]-1]++;
            count-=(n-c1);
            r1++;
          }
          if(s2[arr[i][1]-1]==0){
            s2[arr[i][1]-1]++;
            count-=(n-r1);
            c1++;
          }
          ans.push_back(count);
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends