//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<int> q;
        int n=arr.size();
        int M=100000;
        int count=0;
        vector<int> visited(M+1,false);
        q.push(start);
        while(!q.empty()){
            int nq=q.size();
            for(int i=0;i<nq;i++){
                int p=q.front();
                q.pop();
                if(p==end) return count;
                for(int i=0;i<n;i++){
                    int x=(p*1LL*arr[i])%M;
                    if(visited[x]==false){
                        q.push(x);
                        visited[x]=true;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends