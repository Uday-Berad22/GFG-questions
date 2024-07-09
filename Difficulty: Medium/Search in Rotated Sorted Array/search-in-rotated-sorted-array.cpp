//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int p=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[i-1]) {p=i;break;}
        }
        int left=0,right=p-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]==key) return mid;
            else if(arr[mid]>key) right--;
            else left++;
        }
        left=p;right=arr.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]==key) return mid;
            else if(arr[mid]>key) right--;
            else left++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends