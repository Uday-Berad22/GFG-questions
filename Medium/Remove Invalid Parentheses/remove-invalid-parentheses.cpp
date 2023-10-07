//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    void recurssion(set<string> &ans,string &s,int i,int cO,int cC,string &temp,int &maxi){
        if(i==s.size()){
            if(cO==cC){
                ans.insert(temp);
                int n=temp.size();
                maxi=max(maxi,n);
            }
            return;
        }
        recurssion(ans,s,i+1,cO,cC,temp,maxi);
        if(s[i]!=')'){
            temp.push_back(s[i]);
            if(s[i]=='(')
            recurssion(ans,s,i+1,cO+1,cC,temp,maxi);
            else
            recurssion(ans,s,i+1,cO,cC,temp,maxi);
            temp.pop_back();
        }
        if(s[i]==')'&&cC<cO){
            temp.push_back(s[i]);
            recurssion(ans,s,i+1,cO,cC+1,temp,maxi);
            temp.pop_back();
        }
        
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        string temp="";
        int maxi=0;
        vector<string> f_ans;
        recurssion(ans,s,0,0,0,temp,maxi);
        for(auto &a: ans) {
            if(a.size()==maxi) f_ans.push_back(a);
        }
        return f_ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends