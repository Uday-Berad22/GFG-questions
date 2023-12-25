//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int Recursion(vector<vector<int>> matrix){
        int count=0;
        int n=matrix.size();
        if(n==2){
            return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int temp=matrix[0][i];
            if(count&1){
                temp=-1*temp;
            }
            count=count^1;
            vector<vector<int>> v(n-1);
            for(int j=1;j<n;j++){
                for(int k=0;k<n;k++){
                    if(k==i){
                        continue;
                    }
                    v[j-1].push_back(matrix[j][k]);
                }
            }
            int ans=Recursion(v);
            sum+=(temp*ans);
        }
        return sum;
    }
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
        if(n==1) return matrix[0][0];
        return Recursion(matrix);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends