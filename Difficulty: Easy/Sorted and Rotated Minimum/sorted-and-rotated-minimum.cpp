//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int low=0;
        int n=arr.size();
        int high=n-1;
        while(high-low>1){
            int mid=(high+low)/2;
            if(arr[low]>=arr[high] && arr[mid]>=arr[low]){
                low=mid;
            }
            else if(arr[low]<arr[high] ||  arr[mid]<=arr[high]){
                high=mid;
            }
            else{
                low=mid;
            }
        }   
        return min(arr[low],arr[high]);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends