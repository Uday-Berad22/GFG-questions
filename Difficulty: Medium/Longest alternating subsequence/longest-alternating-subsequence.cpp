//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int miniC=1;
        int maxiC=1;
        int maxi=arr[0];
        int mini=arr[0];
        for(int i=1;i<arr.size();i++){
            if(maxi>arr[i]){
                if(miniC<maxiC+1){
                    mini=arr[i];
                    miniC=maxiC+1;
                }
                else if(miniC==maxiC+1){
                    mini=min(arr[i],mini);
                }
            }
            if(mini<arr[i]){
                if(miniC+1>maxiC){
                    maxi=arr[i];
                    maxiC=miniC+1;
                }
                else if(miniC+1==maxiC){
                    maxi=max(maxi,arr[i]);
                }
            }
        }
        return max(maxiC,miniC);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends