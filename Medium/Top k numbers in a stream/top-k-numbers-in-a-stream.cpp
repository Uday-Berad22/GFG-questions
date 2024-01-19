//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int k) {
        // code here
        vector<vector<int>> ans(N);
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> pq;
        set<pair<int,int>> s;
        queue<pair<int,int>> q;
        bool flag=false;
        for(int i=0;i<N;i++){
           auto it =  s.find({m[arr[i]],-1*arr[i]});
           if(it!=s.end()){
               s.erase(it);
           }
            m[arr[i]]++;
            s.insert({m[arr[i]],-1*arr[i]});
             if(s.size()>k){
                   s.erase(s.begin());
               }
           for(auto it=s.begin();it!=s.end();it++){
               ans[i].push_back(-1*(*it).second);
           }
        }
        for(int i=0;i<N;i++)
          reverse(ans[i].begin(),ans[i].end());
        return ans;
    }
    /*
6 3
1 10 3 1 0 9
Your Code's output is: 
1
1 10
1 3 10
1 3 10

It's Correct output is: 
1
1 10
1 3 10
1 3 10
1
1
Output Difference
1
1 10
1 3 10
1 3 10


1
1*/
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends