//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {

         int i=0, n=s.size();
        long long num=0, mx= -1;
        bool flag=false;
        
        while( i < n ){
            
            if( s[i] >= 48 && s[i] <= 57 ){
                while( i < n && (s[i] >= 48 && s[i] <= 57) ){
                   if( s[i]-'0' == 9 ) flag=true;
                   
                   num = num*10 + (s[i]-'0');
                   i++;
                }
               
                if( flag == false ){
                    mx = max(mx,num);
                }
                else flag=false;
                
                num=0;
               
            }
            else i++;
        }
        
        return mx;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends