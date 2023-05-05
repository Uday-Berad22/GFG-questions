//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    list<int> q;
    list<int> :: iterator  ii;
    map<int,pair<int,list<int> :: iterator>> m;
    int c;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        vector<int> a(cap,-1);
        // v=a;
        c=cap;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(m[key].first==0) return -1;
        auto ite=q.begin();
          q.erase(m[key].second);
        q.push_back(key);
        return m[key].first;
    }
     
    void SET(int key, int value)
    {
        if(m[key].first!=0) {m[key].first=value; 
        auto ite=q.begin();
        
        q.erase(m[key].second);
        q.push_back(key);
        return ;}
        if(q.size()==c){
            int temp=q.front();
            q.pop_front();
            m[temp].first=0;
            // q.push(temp);
        } 
        
        if(m[key].first==0) {
            q.push_back(key);
             m[key].first=value;
             m[key].second=--q.end();
          }
         m[key].first=value;
    }
};
/*
// design the class in the most optimal way

class LRUCache
{
    private:
    unordered_map<int,int> m;
    queue<int> q;
    int c;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        vector<int> a(cap,-1);
        // v=a;
        c=cap;
    }
    
    //Function to return value corresponding to the key.
   
    
    //Function for storing key-value pair.
   
};
*/

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends