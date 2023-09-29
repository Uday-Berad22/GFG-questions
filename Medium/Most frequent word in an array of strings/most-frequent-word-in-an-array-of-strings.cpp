//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Node
{
private:
    Node *links[26];
    bool flag;
    int pc = 0;
    int ew = 0;

public:
    void increasePrefixCount()
    {
        pc++;
    }
    void increaseEndWordCount()
    {
        ew++;
    }
    void decrasePrefixCount()
    {
        pc--;
    }
    void decraseEndWordCount()
    {
        ew--;
    }
    int getPC()
    {
        return pc;
    }
    int getEW()
    {
        return ew;
    }
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
    int insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->isContainsKey(word[i]))
            {
                node->putChar(word[i], new Node());
            }
            node = node->getLink(word[i]);
            node->increasePrefixCount();
        }
        node->setEnd();
        node->increaseEndWordCount();
        return node->getEW();
    }
    // O(word.size())
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->isContainsKey(word[i]))
            {
                return false;
            }
            node = node->getLink(word[i]);
        }
        return node->isEnd();
    }

    // O(prefix.size())
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->isContainsKey(prefix[i]))
            {
                return false;
            }
            node = node->getLink(prefix[i]);
        }
        return true;
    }
    // O(word.size())
    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->isContainsKey(word[i]))
                return 0;
            node = node->getLink(word[i]);
        }
        return node->getEW();
    }
    // O(word.size())
    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->isContainsKey(word[i]))
            {
                return 0;
            }
            node = node->getLink(word[i]);
        }
        return node->getPC();
    }
    // O(word.size())
    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->isContainsKey(word[i]))
                return;
            node = node->getLink(word[i]);
            node->decrasePrefixCount();
        }
        node->decraseEndWordCount();
    }
};
class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        Trie T;
        string ans;
        unordered_map<string,int> m;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(m.find(arr[i])==m.end()){
                m[arr[i]]=i;
            }
            int a=T.insert(arr[i]);
            if(a>maxi){
                maxi=a;
                ans=arr[i];
            }
            else if(a==maxi){
                if(m[arr[i]]>m[ans]){
                    ans=arr[i];
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends