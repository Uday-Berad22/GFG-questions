//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            int n=price.size();
            vector<int> profit(n,0);
            int maxprofit=price[n-1];
            for(int i=n-2;i>=0;i--)
            {
                maxprofit=max(maxprofit,price[i]);
                profit[i]=max(profit[i+1],maxprofit-price[i]);
            }
            int minprice=price[0];
            for(int i=1;i<n;i++)
            {
                minprice=min(minprice,price[i]);
                profit[i]=max(profit[i-1],(price[i]-minprice)+profit[i]);
            }
            return profit[n-1]; 


        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends