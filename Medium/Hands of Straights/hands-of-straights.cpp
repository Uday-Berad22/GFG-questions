//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
    //  
 
          map<int,int> mp;
        for(auto i:hand){
            mp[i]++;
        }
        
       
       
       int e = -1;
       int g = groupSize;
       
       while(mp.size() !=0){
           
           
           
           if(g == 0){
               g = groupSize;
               e = mp.begin()->first;
           }
           
           if(e == -1){
               e = mp.begin()->first;
           }
           
           
           
           
           if(mp.find(e)!=mp.end() and g!=0){
               
               mp[e]--;
               if(mp[e] == 0)mp.erase(e);
               e = e+1;
               g--;
               
           }
           else if(g!=0 and mp.find(e) == mp.end()){
               return false;
           }
           
           
           
           
           
           
       }
       
       
       if(g!=0)return false;
        
     if(mp.size() == 0)return true;
     return false;


    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends