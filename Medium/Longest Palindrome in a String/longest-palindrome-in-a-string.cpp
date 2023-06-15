//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

  bool check(string &s){
    int n=s.size();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i]){
            return false;
        }
    }
    return true;
}
    string longestPalin (string s) {
        int n=s.size();
         int count=0;
         string ans;
         ans+=s[0];
     string temp;
    for(int i=0;i<n;i++){
        temp="";
        temp.push_back(s[i]);
        for(int j=i+1;j<n;j++){
            temp.push_back(s[j]);
            if(temp.size()>ans.size()){
            if(check(temp)){
               
                    ans=temp;
                }
            }
        }
    }
    // return count;
    //     vector<bool> e(n),o(n);
    //     for(int i=0;i<n;i++){
    //         o[i]=true;
    //     }
    //     string ans2;

    //     for(int i=0;i<n-1;i++){
    //         if(s[i]==s[i+1]){
    //             if(ans2.size()==0){
    //             ans2.push_back(s[i]);
    //             ans2.push_back(s[i+1]);
    //             }
    //             e[i]=true;
    //         }
    //     }
    //     int io=0;
    //     int ie=0;
    //     int x=0,y=0;
    //     int diff=-1;
    //     int lo=0;
    //     int le=0;
    //     for(int i=2;i<n;i++){
    //         int r=0,c=i;
    //         if(i%2==0){
    //         io=lo+1;
    //         lo=io; 
    //         }
    //         if(i%2!=0)
    //         {
    //             ie=le+1;
    //             le=ie;
    //         }
            
          
    //         while(c<n&&r<n){
    //             if(i%2==0){
    //                 if(s[r]!=s[c]){
    //                     o[io]=false;
    //                 }
    //                 else{
    //                     if(o[io]==true){
    //                         o[io]=true;
    //                          if(abs(r-c)>diff){
    //                           diff=abs(r-c);
    //                           x=r;y=c;
    //                          }
    //                     }
    //                     else{
    //                          o[io]=false;
    //                     }
    //                 }
    //                 io++;
    //             }
    //             else{
    //                 if(s[r]!=s[c]){
    //                     e[ie]=false;
    //                 }
    //                 else{
    //                     if(e[ie]==true){
    //                         e[ie]=true;
    //                          if(abs(r-c)>diff){
    //                           diff=abs(r-c);
    //                           x=r;y=c;
    //                          }
    //                     }
    //                     else{
    //                          e[ie]=false;
    //                     }
    //                 }
    //                 ie++;
    //             }
    //             // if(r==3&&c==6){
    //             //     cout<<ie<<endl;
    //             //     cout<<e[ie]<<endl;
    //             // }
    //             r++;
    //             c++;
    //         }
    //     }
    //     string ans;
    //     // cout<<x<<" "<<y<<endl;
    //     for(int i=x;i<=y;i++){
    //         ans.push_back(s[i]);
    //     }
    //     if(ans.size()<ans2.size()){
    //         ans=ans2;
    //     }
    //     if(ans.size()==0){
    //     ans+=s[0];
    //     }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends