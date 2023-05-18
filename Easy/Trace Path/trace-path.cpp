//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int c0=m,r0=n;
        int x=0,y=0;
        int mi=m;
        int ni=n;
        int l=0,r=0,u=0,d=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L') l++;
            else if(s[i]=='R') r++;
            else if(s[i]=='D') d++;
            else u++;
        }
        int count=0,Lm=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                count++;
            }
            else if(s[i]=='R')
            {
                Lm=max(count,Lm);
                count=0;
                
            }
        }
         Lm=max(count,Lm);
        count=0;
        int Rm=0;
         for(int i=0;i<s.size();i++){
            if(s[i]=='R'){
                count++;
            }
            else if(s[i]=='L')
            {
                Rm=max(count,Rm);
                count=0;
                
            }
        }
         Rm=max(count,Rm);
        int x1=max(Rm,Lm);
        int Um=0,Dm=0;
        count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='U'){
                count++;
            }
            else if(s[i]=='D')
            {
                Um=max(count,Um);
                count=0;
                
            }
            
        }
         Um=max(count,Um);
        count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='D'){
                count++;
            }
            else if(s[i]=='U')
            {
                Dm=max(count,Dm);
                count=0;
                
            }
        }
        Dm=max(count,Dm);
        int x2=max(Dm,Um);
        // cout<<x1<<" "<<x2<<endl;
        if(x2>=n) return 0;
        if(x1>=m) return 0;
        if(l>r){
            mi=mi-1;
        }
        else if(l<r) {
            m=m-1;
        }
        if(u>d){
           
            n-=1;
        }
        else if(d<u){
             ni-=1;
        }
        unordered_set<int> s1,s2;
        for(int i=0;i<s.size();i++){
            if(x<=(-1*m)||x>=mi){
                return 0;
            }
            if(y<=(-1*n)||y>=ni){
                return 0;
            }
            s1.insert(x);
            s2.insert(y);
            if(s1.size()>c0){
                return 0;
            }
            if(s2.size()>r0) return 0;
            if(s[i]=='L')
            x--;
            else if(s[i]=='R')
            x++;
            else if(s[i]=='U')
            y++;
            else
            y--;
        }
        s1.insert(x);
            s2.insert(y);
         if(s1.size()>c0){
                return 0;
            }
            if(s2.size()>r0) return 0;
        if(x<=(-1*m)||x>=mi){
                return 0;
            }
            if(y<=(-1*n)||y>=ni){
                return 0;
            }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends