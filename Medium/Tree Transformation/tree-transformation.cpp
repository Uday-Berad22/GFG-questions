//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        if(N<=2)
        return 0;
        unordered_map<int,int> m;
        for(int i=0;i<p.size();i++){
            m[p[i]]++;
        }
        int count=0;
        for(int i=0;i<N;i++){
            if(m[i]==0){
               count++;
            }
        }
        if(m[0]==1)
        count++;
        return N-count-1;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends