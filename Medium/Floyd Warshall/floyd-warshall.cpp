//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    for(int via=0;via<n;via++){
	        for(int u=0;u<n;u++){
	            if(u!=via){
	                for(int v=0;v<n;v++){
	                    if(v!=via&&u!=v){
	                        if(matrix[u][v]==-1){
	                            if(matrix[u][via]!=-1&&matrix[via][v]!=-1){
	                                matrix[u][v]=matrix[u][via]+matrix[via][v];
	                            }
	                        }
	                        else{
	                            if(matrix[u][via]!=-1&&matrix[via][v]!=-1){
	                                matrix[u][v]=min(matrix[u][v],matrix[u][via]+matrix[via][v]);
	                            }
	                        }
	                    }
	                }
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends