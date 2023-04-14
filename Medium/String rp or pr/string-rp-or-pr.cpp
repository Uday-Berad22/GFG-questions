//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string s){
      //code here
      long long cost=0;
      int n=s.size();
      int i=0;
      while(i<n){
          if(s[i]=='p'||s[i]=='r'){

              
              if(X>=Y){
                stack<int> s1,s2;
                  string temp;
              while(i<n&&(s[i]=='p'||s[i]=='r')){
                  if(s1.empty()&&s[i]=='r'){
                      temp.push_back('r');
                      i++;
                  }
                   else if(s1.empty()&&s[i]=='p'){
                      s1.push('p');
                      i++;
                  }
               else if(s1.top()=='p'&&s[i]=='p'){
                    s1.push(s[i]);
                    i++;
                 } 
                 else if(s[i]=='r'){
                     s1.pop();
                     cost+=X;
                     i++;
                 }
              }
              while(!s1.empty()){
                  temp.push_back(s1.top());
                  s1.pop();
              }
              for(int j=0;j<temp.size();j++){
                  if(s2.empty()){
                      s2.push(temp[j]);
                  }
                  else if(s2.top()=='r'&&temp[j]=='p'){
                      cost+=Y;
                      s2.pop();
                  }
                  else{
                      s2.push(temp[j]);
                  }
              }
              }
              else if(X<Y){
                 stack<int> s1,s2;
                  string temp;
              while(i<n&&(s[i]=='p'||s[i]=='r')){
                  if(s1.empty()&&s[i]=='p'){
                      temp.push_back('p');
                      i++;
                  }
                else  if(s1.empty()&&s[i]=='r'){
                      s1.push('r');
                      i++;
                  }
             else   if(s1.top()=='r'&&s[i]=='r'){
                    s1.push(s[i]);
                    i++;
                 } 
                 else if(s[i]=='p'){
                     s1.pop();
                     cost+=Y;
                     i++;
                 }
              }
              while(!s1.empty()){
                  temp.push_back(s1.top());
                //   cout<<"UES"<<endl;
                  s1.pop();
              }
              for(int j=0;j<temp.size();j++){
                  if(s2.empty()){
                      s2.push(temp[j]);
                  }
                 else if(s2.top()=='p'&&temp[j]=='r'){
                    //  cout<<"UEUO"<<endl;
                      cost+=X;
                      s2.pop();
                  }
                  else{
                      s2.push(temp[j]);
                  }
              }
              }
          }
          else{
              i++;
          }
      }
      return cost;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends