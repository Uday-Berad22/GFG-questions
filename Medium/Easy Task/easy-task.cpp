//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
bool cmp(char a,char b) {
    return a> b;
}
class Solution{
public:
    vector<char> easyTask(int n,string s,int b,vector<vector<string>> &q){
        vector<char> v;
    //   vector<vector<int>>  help;

        // vector<int> last(26,0);
        //  help.push_back(last);
        // for(int i=0;i<n;i++){
        //     last[int(s[i])-97]+=1;
        //     // cout<<last[int(s[i])-65]<<endl;
        //     help.push_back(last);
        //     // cout<<last.size()<<endl;
        //     // cout<<help[i].size();
        // }
        for(auto & temp :  q){
            if(temp[0]=="1")
            {
                int x=stoi(temp[1]);
                char c=(temp[2][0]);
                s[x]=c;
            }
            else
            {
                int start=stoi(temp[1]);
                int end=stoi(temp[2]);
                int k=stoi(temp[3]);
                // string y=s;
                // sort(y.begin()+start,y.begin()+end+1,cmp);
                // sort(y.begin(),y.end(),cmp);
                vector<int> xyz(26,0);
            //   cout<<help[end+1].size();
                for(int i=start;i<=end;i++){
                    xyz[s[i]-'a']++;
                }
                char ans;
                int count=0;
                for(int i=25;i>=0;i--){
                    count+=xyz[i];
                    if(count>=k)
                    {
                        // cout<<char(i+97)<<endl;
                        ans=char(i+97);
                        break;
                    }
                }
                v.push_back(ans);
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends