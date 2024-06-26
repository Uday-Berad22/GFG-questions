//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        vector<int> freq(27,0);
        for(int i=0;i<s.size();i++){
            freq[(s[i]-'a')+1]++;
        }
        int x=0;
        int y=0;
        for(int i=1;i<=26;i++){
            if(freq[i]==0) continue;
            if(i%2==0 && freq[i]%2==0){
                x++;
            }
            else if(i%2!=0 && freq[i]%2!=0){
                y++;
            }
        }
        return (x+y)%2==0? "EVEN": "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends