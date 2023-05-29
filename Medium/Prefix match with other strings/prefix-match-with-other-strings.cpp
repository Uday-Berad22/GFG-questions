//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int klengthpref(string v[], int n, int k, string Pattern){    
        int ans=0;
        for(int i=0;i<n;i++){
            // string temp=v[i].first;
            int count=0;
            for(int j=0;j<v[i].size();j++){
                if(j<Pattern.size()&&Pattern[j]==v[i][j]){
                    count++;
                    if(count==k){
                     ans++;
                 }
                }
                else{
                    break;
                }
            }
            
        }
       
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends