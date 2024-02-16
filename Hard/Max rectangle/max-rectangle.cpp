//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  long long getMaxArea( vector<long long> &arr, int n)
    {
        // Your code here
        stack<long long> prevSmaller,nextSmaller;
        vector<long long> v(n),v2(n);
        v[0]=0;
        prevSmaller.push(0);
        int j=n-1;
        v2[j]=n-1;
        nextSmaller.push(n-1);
        j--;
        for(int i=1;i<n;i++){
           
            while(!nextSmaller.empty() && arr[nextSmaller.top()]>=arr[j]){
                nextSmaller.pop();
            }
            if(nextSmaller.empty()){
                v2[j]=n-1;
            }
            else{
                v2[j]=nextSmaller.top()-1;
            }
            nextSmaller.push(j);
            j--;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            while(!prevSmaller.empty() && arr[prevSmaller.top()]>=arr[i]){
                prevSmaller.pop();
            }
            if(prevSmaller.empty()){
                v[i]=0;
            }
            else{
                v[i]=prevSmaller.top()+1;
            }
            prevSmaller.push(i);
            
            v2[i]= v2[i]-v[i]+1;
            ans=max(ans,arr[i]*v2[i]);
        }
        
        
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<long long>  histogram(m,0);
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0){
                    histogram[j]=0;
                }
                else{
                    histogram[j]++;
                }
            }
            ans=max(ans,getMaxArea(histogram,m));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends