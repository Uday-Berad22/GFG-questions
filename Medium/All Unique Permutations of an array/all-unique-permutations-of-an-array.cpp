//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void rec(vector<int> &arr,int index,set<vector<int>> &s){
        int n=arr.size();
        if(index==n){
            s.insert(arr);
        }
        for(int i=index;i<n;i++){
            swap(arr[i],arr[index]);
            rec(arr,index+1,s);
        }
        for(int j=index;j<n-1;j++){
            swap(arr[j],arr[j+1]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>> s;
        vector<vector<int>> ans;
        rec(arr,0,s);
        for(auto &vec:s){
            ans.push_back(vec);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends