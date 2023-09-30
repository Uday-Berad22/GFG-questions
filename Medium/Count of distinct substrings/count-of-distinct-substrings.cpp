//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
class Node{
    private:
    Node *links[26];
    bool flag;
    public: 
    bool isContainsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void putChar(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node *getLink(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};


class Trie {
    Node *root;
public:
    int count=0;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        if(root->isEnd()==false){
            count++;
        }
        root->setEnd();
        for(int i=0;i<word.length();i++){
            if(!node->isContainsKey(word[i])){
                node->putChar(word[i],new Node());
            }
            node=node->getLink(word[i]);
            if(node->isEnd()==false){
                count++;
            }
            node->setEnd();
        }
    }
};

int countDistinctSubstring(string s)
{
    //Your code here
     Trie T;
    int n=s.size();
    for(int i=0;i<n;i++){
        T.insert(s.substr(i,n-i));
    }
    return T.count;
}