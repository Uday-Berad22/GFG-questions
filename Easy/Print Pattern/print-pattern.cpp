//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int flag=0;
    int counter=0;
    vector<int> helper(vector<int>&ans, int &n, int orig){
        
        if(n==orig && counter==1){
            return ans;
        
            
        }        
        else{
            if(n>0 && flag==0){
         
            n-=5;
        ans.push_back(n);
        counter=1;
        return helper(ans,n,orig);
            
        }
        else{
            n+=5;
            ans.push_back(n);
            flag=1;
            counter=1;
            return helper(ans,n,orig);
        }
    } 
    }
    vector<int> pattern(int n){
        // code here
        if(n<=0)return {n};
        vector<int>ans;
        ans.push_back(n);
         helper(ans,n,n);
         return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends