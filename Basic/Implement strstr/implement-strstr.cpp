//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     for(int i=0;i<s.size();i++){
         for(int j=0;j<x.size();j++){
             if(s[i+j]!=x[j]){
                 break;
             }
             if(j==x.size()-1){
                 if(s[i+j]==x[j]){
                     return i;
                 }
             }
         }
     }
     return -1;
}