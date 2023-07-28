//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    vector<vector<int>> directions={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
    public:
    int BFS(vector<int> KnightPos,vector<int>&TargetPos,int N,vector<vector<bool>> &visited){
        int ans=INT_MAX;
        visited[KnightPos[0]][KnightPos[1]]=true;
        for(auto a: directions){
            int i=KnightPos[0]+a[0],j=KnightPos[1]+a[1];
            if(i<0||j<0||i>=N||j>=N) continue;
            if(i==TargetPos[0]&&j==TargetPos[1]) return 1;
            if(!visited[i][j]){
            ans=min(BFS({i,j},TargetPos,N,visited),ans);
            }
        }
        return ans;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<bool>> visited(N,vector<bool> (N,false));
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0]-1,KnightPos[1]-1});
	    visited[KnightPos[0]-1][KnightPos[1]-1]=true;
	    int count=0;
	    while(!q.empty()){
	        int m=q.size();
	        count++;
	        for(int k=0;k<m;k++){
	        KnightPos[0]=q.front().first;KnightPos[1]=q.front().second;
	        q.pop();
	        for(auto a: directions){
            int i=KnightPos[0]+a[0],j=KnightPos[1]+a[1];
            if(i<0||j<0||i>=N||j>=N) continue;
            if(i==TargetPos[0]-1&&j==TargetPos[1]-1) return count;
            if(!visited[i][j]){
            q.push({i,j});
            visited[i][j]=true;
            }
          }
	        }
	    }
        return 0;
	}
	//        if(KnightPos[0]<0||KnightPos[1]<0||KnightPos[0]>=N||KnightPos[1]>=N) return false;
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends