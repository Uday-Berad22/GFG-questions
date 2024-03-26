//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool isAdditiveSequence(string n) {
        // Your code here
        int m=n.size();
        string a;
        int flag=-1;
        for(int i=0;i<m;i++){
            a.push_back(n[i]);
            string b;
            if(1){
                for(int j=i+1;j<m;j++){
                    b.push_back(n[j]);
                    string c;
                    if( b.size()<9 && a.size()<9){
                        for(int k=j+1;k<m;k++){
                           c.push_back(n[k]); 
                           if(c.size()>9){
                               break;
                           }
                           long long  x=stoll(a);
                            long long  y=stoll(b);
                            long long  z=stoll(c);
                           if(x+y==z){
                               flag=k;
                               break;
                           }
                        }
                        if(flag!=-1){
                            break;
                        }
                    }
                }
                if(flag!=-1){
                    // cout<<"Hello"<<" "<<i<<endl;
                    a="";
                    if(flag==m-1){
                        return true;
                    }
                    flag=-1;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends