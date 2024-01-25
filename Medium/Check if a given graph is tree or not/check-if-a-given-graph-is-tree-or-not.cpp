//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
  
    bool isCycle(int i,vector<vector<int>> &graph,vector<int> &stk,vector<int> &visited,int prevnbr,int &count,vector<int> &num){
        count++;
        for(auto &nbr: graph[i]){
            if(visited[nbr]==true&&stk[nbr]==false){
                count+=num[nbr];
            }
            
            else if(visited[nbr]==true&&stk[nbr]==true&&nbr!=prevnbr) return true;
            
            else if(visited[nbr]==false)
                {
                    visited[nbr]=true;
                    stk[nbr]=true;
                    if( isCycle(nbr,graph,stk,visited,i,count,num)) return true;
                    stk[nbr]=false;
                }
        }
        
        return false;
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        if(n==1&&m==0) return 1;
        vector<vector<int>> graph(n);
        vector<int> visited(n,false);
        vector<int> stk(n,false);
        for(auto &a: adj){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
            if(a[0]==a[1]) return 0;
        }
        int maxi=0;
        vector<int> num(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]!=true){
                int count=0;
                visited[i]=true;
                stk[i]=true;
                if(isCycle(i,graph,stk,visited,-1,count,num)) return 0;
                stk[i]=false;
                num[i]=count;
                maxi=max(count,maxi);
            }
        }
        return maxi==n?1:0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends