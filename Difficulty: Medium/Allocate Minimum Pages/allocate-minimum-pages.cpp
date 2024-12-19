//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int mid,vector<int> &arr,int k){
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            
            sum+=arr[i];
            if(arr[i]>mid){
                return false;
            }
            if(sum>mid ){
                sum=arr[i];
                k--;
            }
            else if(sum==mid){
                sum=0;
                k--;
            }
            // else if(i==n-1) sum=0;
            
        }
        if(sum>0){
            k--;
            sum=0;
        }
        // if(sum>mid) return false;
        return k>=0 && sum==0;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k){
            return -1;
        }
        int low=0;
        int high=INT_MAX;
        while(high-low>1){
            int mid=(low+(high-low)/2);
            if(check(mid,arr,k)){
                high=mid;
            }
            else{
                low=mid;
            }
        }
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends