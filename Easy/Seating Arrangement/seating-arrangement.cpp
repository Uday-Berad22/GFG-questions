//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    bool is_possible_to_get_seats(int n, int m, vector<int>& a){
        int count=n;
        if(a.size()==1&&n==1){
            return a[0]==0;
        }
        else if(a.size()==1&&n==0){
            return 1;
        }
        if(n==0) return 1;
        
        for(int i=0;i<m-1;i++){
            if(i==0&&(a[i]==0&&a[i+1]!=1)){
                a[i]=1;
                count--;
            }
            else if(a[i-1]!=1&&(a[i]==0&&a[i+1]!=1)){
                a[i]=1;
                count--;
            }
        }
        if(a[m-1]==0&&a[m-2]==0){
            count--;
        }
        return count<=0;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends