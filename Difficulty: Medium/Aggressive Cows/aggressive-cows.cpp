//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool check(vector<int> &stalls, int k,int mid){
        int count=1;
        int prev=stalls[0];
        int n=stalls.size();
        
        for(int i=1;i<n;i++){
            if(stalls[i]-prev>=mid){
                count++;
                prev=stalls[i];
            }
        }
        // cout<<mid<<" --> "<<count<<endl;
        return count>=k;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        //..........
        //l---l----l
        //Brut Force: (1toINT_MAX)* N -->   O(Nlogn)
        // TTTTT TF FFFFF
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        
        int low=-1;
        int high=1e9+1;
        while(high-low>1){
            int mid= (low+(high-low)/2);
            if(check(stalls,k,mid)){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends