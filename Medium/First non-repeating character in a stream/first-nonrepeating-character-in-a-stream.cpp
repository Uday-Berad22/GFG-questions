//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans;
		    int m[26]={0};
		    string s;
		    int n=A.size();
		    for(int i=0;i<n;i++){
		        if(m[A[i]-'a']==0){
		            s+=(A[i]);
		        }
		        m[A[i]-'a']+=1;
		        char x='#';
		        int nn=s.size();
		        for(int j=0;j<nn;j++){
		            if(m[s[j]-'a']==1){
		                x=s[j];
		                break;
		            }
		        }
		        ans+=x;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends