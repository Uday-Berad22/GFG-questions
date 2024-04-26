//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        // r d l u
        int previ=-1;
        int prevj=-1;
        int i=0;
        int j=0;
        char dir='r';
        while(i<n && j<m && i>=0 &&  j>=0){
            previ=i;
            prevj=j;
            if(matrix[i][j]==1){
                matrix[i][j]=0;
                if(dir=='r'){
                    dir='d';
                    i+=1;
                }
                else if(dir=='d'){
                    dir='l';
                    j-=1;
                }
                else if(dir=='l'){
                    dir='u';
                    i-=1;
                }
                else if(dir=='u'){
                    dir='r';
                    j+=1;
                }
            }
            else{
                if(dir=='r'){
                    j+=1;
                }
                if(dir=='d'){
                    i+=1;
                }
                if(dir=='l'){
                    j-=1;
                }
                if(dir=='u'){
                    i-=1;
                }
            }
            
        }
        return {previ,prevj};
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends