//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        priority_queue<int> pq;
        unordered_map<char,int> m;
        for(auto c: s)
        {
            m[c]++;    
        }
        for(auto a: m){
            pq.push(a.second);
        }
        while(k--){
            int x=pq.top();
            pq.pop();
            pq.push(x-1);
        }
        int ans=0;
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            ans= ans+ (x*x);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends