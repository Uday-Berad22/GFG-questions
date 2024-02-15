//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int> maxHeap;
    //Function to insert heap.
    void insertHeap(int &x)
    {

        if(maxHeap.size()>minHeap.size()){
            if(maxHeap.top()>x){
                maxHeap.push(x);
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else{
                minHeap.push(x);
            }
        }
        else{
            if(maxHeap.size()==0){
                maxHeap.push(x);
            }
            else if(maxHeap.top()<x){
                minHeap.push(x);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else{
                maxHeap.push(x);
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxHeap.size()==0) return -1;
        if(maxHeap.size()==minHeap.size()){
            int a=maxHeap.top();
            int b=minHeap.top();
            double ans= (a+b)/2.0;
            return ans;
        }
        return maxHeap.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends