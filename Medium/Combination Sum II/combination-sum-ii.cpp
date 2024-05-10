//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void rec(int i,vector<int> &arr,int n,int k,set<vector<int>> &s,vector<int> &temp){
        if(k<=0 || i>=n){
            if(k==0){
                s.insert(temp);
            }
            return;
        }
        rec(i+1,arr,n,k,s,temp);
        temp.push_back(arr[i]);
        rec(i+1,arr,n,k-arr[i],s,temp);
        temp.pop_back();
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> temp;
        sort(arr.begin(),arr.end());
        rec(0,arr,n,k,s,temp);
        for(auto &v: s){
            ans.push_back(v);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends