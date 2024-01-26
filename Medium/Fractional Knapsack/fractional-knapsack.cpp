//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>> fractions(n);
        for(int i=0;i<n;i++){
            int value=arr[i].value;
            int weight=arr[i].weight;
            double frac=(value*1.0)/weight;
            fractions[i]={frac,i};
        }
        double profit=0;
        sort(fractions.begin(),fractions.end());
        for(int i=n-1;i>=0;i--){
            int j=fractions[i].second;
            int w=arr[j].weight;
            
            if(W>=w){
                 profit= profit+arr[j].value;
                 W-=w;
            }
            else{
                profit+= W*(fractions[i].first);
                break;
            }
        }
        return profit;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends