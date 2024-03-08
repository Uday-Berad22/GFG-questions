//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    int hash[26]={0};
	    unordered_map<int,int> m;
	    for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
	    }
	    sort(hash,hash+26);
	    for(int i=0;i<26;i++){
	        if(hash[i]!=0){
	            m[hash[i]]++;
	        }
	    }
	    if(m.size()>2){
	        return false;
	    }
        if(m.size()==1) return true;
        auto it=m.begin();
        auto it1=it;
        auto it2=++it;
        if(it1-> second ==1 ){
            if(it1->first==1 || ((it1->first) -(it2->first))==1){
                return true;
            }
            return false;
        }
        if(it2-> second ==1 ){
            if(it2->first==1 ||((it2->first) -(it1->first))==1){
                return true;
            }
            return false;
        }
        
            return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends