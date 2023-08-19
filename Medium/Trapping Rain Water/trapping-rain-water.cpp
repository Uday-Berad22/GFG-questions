//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        vector<int> helper(n,-1);
        for(int i=n-2;i>=0;i--){
            helper[i]=max(helper[i+1],height[i+1]);
        }
        int var=height[0];
        long long ans=0;
        int flag=0;
        for(int i=0;i<n;i++){
            if(height[i]>var){
                var=height[i];
            }
            else if(helper[i]>=height[i]){
                ans=ans+(min(var,helper[i])-height[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends