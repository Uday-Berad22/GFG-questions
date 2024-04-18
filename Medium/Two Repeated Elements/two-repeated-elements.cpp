//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        for(int i=0;i<n+2;i++){
            arr[(arr[i]%(n+2))]= arr[(arr[i]%(n+2))]+(n+2);
        }   
        vector<int> ans;
        for(int i=0;i<n+2;i++){
            int x=arr[i];
            int m=n+2;
            if((x/m)>=2){
                ans.push_back(i);
            } 
        }   
        for(int i=n+2-1;i>=0;i--){
            if((arr[i]%(n+2))==ans.back()){
                return ans;
            }
            else if((arr[i]%(n+2))==ans.front()){
                swap(ans[0],ans[1]);
                return ans;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends