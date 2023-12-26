//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      int n=a.size();
      int m=a[0].size();
      vector<vector<int>> prefix(n+1,vector<int> (m+1,0));
      vector<unordered_map<int,pair<int,int>>> maps(m+1);
      pair<int,int> ans1={-1,-1},ans2;
      int val=-1;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            prefix[i+1][j+1]=prefix[i+1][j]+prefix[i][j+1]+a[i][j]-prefix[i][j];
            // if(maps[j+1].find(prefix[i+1][j+1])==maps[j+1].end()){
            //     maps[j+1][prefix[i+1][j+1]]={i+1,j+1};
            // }
            if(prefix[i+1][j+1]==0&&val==-1){
                ans2={i+1,j+1};
                ans1={1,1};
                val=(i+1)*(j+1);
            }
            if(prefix[i+1][j+1]==0&&val<((i+1)*(j+1))){
                ans2={i+1,j+1};
                ans1={1,1};
                val=(i+1)*(j+1);
            }
            // cout<<prefix[i+1][j+1]<<" ";
        }   
        // cout<<endl;
      }
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
            //   int needed=-1*prefix[i+1][j+1];
              for(int k=0;k<=i;k++){
                for(int z=0;z<=j;z++){
                    if(k==i&&z==j) continue;
                    int ne= prefix[i][j]-prefix[i][z]-prefix[k][j]+ prefix[k][z];
                    
                    if(ne==0){
                        int l=j-z;
                        int b=i-k;
                        // if(k==0&&z==1){
                        //     cout<<ne<<"--"<<l*b<<" "<<i<<" "<<j<<endl;
                        // }
                        if(k+1>i||z+1>j)
                        continue;
                        if(l*b>val){
                            ans1={k+1,z+1};
                            ans2={i,j};
                            val=l*b;
                        }
                        if(l*b==val){
                            if(ans1.second==z+1){
                                if((ans2.first-ans1.first)<(i-(k+1))){
                                     ans1={k+1,z+1};
                                     ans2={i,j};
                                     val=l*b;
                                }
                            }
                            else{
                                if(ans1.second>z+1){
                                     ans1={k+1,z+1};
                                     ans2={i,j};
                                     val=l*b;
                                }
                            }
                            // if(val==2&&k==0&&z==1)
                            // cout<<i<<" "<<j<<" "<<k+1<<" "<<z+1<<endl;
                        }
                    }
                }
              }
          }
      }
      vector<vector<int>> ans;
    //   cout<<ans1.first-1<<" "<<ans1.second-1<<" "<<ans2.first-1<<" "<<ans2.second-1<<endl;
      for(int i=ans1.first-1;i<ans2.first;i++){
          vector<int> temp;
          for(int j=ans1.second-1;j<ans2.second;j++){
              temp.push_back(a[i][j]);
          }
          ans.push_back(temp);
      }
      return ans;
  }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends