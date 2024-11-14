//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        // code here
        string alien="";
        map<char,vector<char>> m;
        // unordered_set<char> s;
        unordered_map<char,int> indgree;
        
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<dict[i].size();j++){
                indgree[dict[i][j]]+=0;
                if(i+1<n && j<dict[i+1].size() &&  flag ==0 && dict[i][j]!=dict[i+1][j]){
                    m[dict[i][j]].push_back(dict[i+1][j]);
                    // cout<<dict[i][j]<<" "<<dict[i+1][j]<<endl;
                    indgree[dict[i+1][j]]++;
                    flag=1;
                  
                }
                
            }
        }
        queue<char> q;
        
        for(auto a : indgree){
            if(a.second==0){
                q.push(a.first);
            }
        }
        
        while(0!=q.size()){
            
            auto node=q.front();
            q.pop();
            alien.push_back(node);
            for(auto nbr: m[node]){
                // cout<<"H->"<<nbr<<endl;
                indgree[nbr]--;
                if(indgree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        // cout<<alien<<endl;
        return alien;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends