//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

vector<bool> v(1000002,true);
vector<int> prime;
class Solution{
public:
    void precompute(){
        v[0]=v[1]=false;
        for(int i=2;i<1000002;i++){
            if(v[i]==true){
                for(int j=i*2;j<1000002;j=j+i){
                    v[j]=false;
                }
            }
        }
        for(int i=0;i<1000002;i++){
            if(v[i]==true)
            prime.push_back(i);
        }
    }
    void dfs(vector<vector<int>> &g,int i,vector<int> &visited,int &count,int &n){
        for(auto j: g[i]){
            if(visited[j]==0){
                count++;
                 visited[j]=1;
               dfs(g,j,visited,count,n);
            }
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        int ans=0;
        if(m==0) return -1;
        vector<int> visited(n+1,0);
        for(int i=1;i<=n;i++){
            if(visited[i]==1)
            continue;
            int count=1;
            visited[i]=1;
                dfs(g,i,visited,count,n);
            ans=max(count,ans);
        }
        if(ans==0) return -1;
        return prime[ans-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends