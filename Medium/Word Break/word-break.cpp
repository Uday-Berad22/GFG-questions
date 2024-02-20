//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    bool rec(int i,string s,vector<string> &dictionary,unordered_map<string,int> &m){
        int n=s.size();
        if(i>=n){
            return true;
        }
        string temp="";
        for(int j=i;j<n;j++){
            temp.push_back(s[j]);
            if(m[temp]>0){
                if(rec(j+1,s,dictionary,m)){
                    return true;
                }
            }
        }
        return false;
    }
    
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            m[dictionary[i]]++;
        }

        return rec(0,s,dictionary,m);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends