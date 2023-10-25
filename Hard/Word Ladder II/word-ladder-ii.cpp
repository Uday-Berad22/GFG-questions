//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {

public:
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({startWord});
        unordered_set<string> s(wordList.begin(),wordList.end());
        vector<string> usedAtLevel;
        int level=0;
        int lastLevel=INT_MAX;
        int lastsize=0;
        s.erase(startWord);
        while(!q.empty()){
            vector<string> temp=q.front();
            q.pop();
            string str=temp.back();
            // if(str==targetWord) break;
            if(temp.size()>lastsize){
                // cout<<temp.size()<<endl;
                for(auto a: usedAtLevel){
                    s.erase(a);
                }
                lastsize++;
            }
             if(str==targetWord&&(ans.size()==0||ans[0].size()==temp.size())){
                           ans.push_back(temp);
            }
            for(int i=0;i<str.size();i++){
                char original=str[i];
                for(char c='a';c<='z';c++){
                    str[i]=c;
                    if(s.find(str)!=s.end()){
                        temp.push_back(str);
                        q.push(temp);
                       
                        temp.pop_back();
                        
                        
                        usedAtLevel.push_back(str);
                    }
                }
                str[i]=original;
            }
        }
        // while(!q.empty()){
        //     vector<string> temp=q.front();
        //     q.pop();
        //     string str=temp.back();
        //     if(str==targetWord){
        //         ans.push_back(temp);
        //     }
        // }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends