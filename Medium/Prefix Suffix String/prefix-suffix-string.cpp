//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        int mcount=0;
        for(int i=0;i<s2.size();i++){
            for(int j=0;j<s1.size();j++){
                if(s1[j].size()>=s2[i].size()){
                    int count=0;
                for(int k=0;k<s2[i].size();k++){
                    if(s2[i][k]==s1[j][k]){
                        count++;
                        continue;
                    }
                    else{
                        break;
                    }
                }
                if(count==s2[i].size()){
                    // cout<<s2[i]<<endl;
                    mcount++;
                    break;
                }
                count=0;
                int x=s1[j].size()-1;
                //  cout<<s2[i]<<endl;
                //  cout<<s1[j]<<endl;
                 for(int k=s2[i].size()-1;k>=0;k--){
                    if(s2[i][k]==s1[j][x]){
                        // cout<<s2[i][k]<<" ";
                        count++;
                        // continue;
                    }
                    else{
                        break;
                    }
                    x--;
                }
                // cout<<endl;
                if(count==s2[i].size()){
                    // cout<<s2[i]<<endl;
                    mcount++;
                    break;
                }
               }
            }
        }
        return mcount;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends