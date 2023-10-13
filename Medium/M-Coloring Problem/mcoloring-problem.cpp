//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool dfs(int i,bool graph[101][101],int m,int n,vector<int> &colors){
        if(colors[i]!=0) return true;
        int f=0;
        int maxi=INT_MIN;
        int cnt1=0;
        for(int k=1;k<=m;k++){
            // cout<<k<<" "<<i<<endl;
            int flag=0;
            for(int j=0;j<n;j++){
                if(graph[i][j]==true){
                    if(colors[j]==k){
                        flag=1;
                        break;
                    }
                }
            }
           
            if(flag==0){
                int flag1=0;
                int count=0;
                int cnt=0;
                colors[i]=k;
                for(int j=0;j<n;j++){
                    if(graph[i][j]==true&&colors[j]==0){
                        count++;
                        if(dfs(j,graph,m,n,colors)){
                            cnt++;
                        }
                        else{
                            flag1=1;
                            break;
                        }
                    }
                }
               if(flag1==0){
                   return true;
               }
            }
        }
        // if(maxi!=cnt1){
        //     return false;
        // }
        colors[i]=0;
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colors(n,0);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<graph[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            dfs(i,graph,m,n,colors);
        }
        // sort(colors.begin(),colors.end());
        for(int i=0;i<n;i++){
            if(colors[i]==0)return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends