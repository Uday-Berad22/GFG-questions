//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Node
{
private:
    Node *links[26];
    bool flag;

public:
    bool isContainsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void putChar(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *getLink(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    // O(word.size())
    int insert(string word,int t)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if(t==0){
                if (!node->isContainsKey(word[i]))
                {
                    node->putChar(word[i], new Node());
                }
                node = node->getLink(word[i]);
            }
            else{
                if(!node->isContainsKey(word[i]))
                {
                    return i;
                }
                 node = node->getLink(word[i]);
            }
        }
        node->setEnd();
        return word.length();
    }
};

class Solution{
  public:
    string longestCommonPrefix (string arr[], int N)
    {
        Trie T;
        int mini=INT_MAX;
        T.insert(arr[0],0);
        for(int i=0;i<N;i++){
            mini=min(mini,T.insert(arr[i],1));
        }
        if(mini==0) return "-1";
        return  arr[0].substr(0,mini);
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends