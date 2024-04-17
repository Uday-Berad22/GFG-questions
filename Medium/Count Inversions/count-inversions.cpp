//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
      void merge(long long  arr[],long long n,int si,int mid,int ei,long long  &count){
         vector<long long > leftPart;
         for(int i=si;i<=mid;i++){
             leftPart.push_back(arr[i]);
         }
         vector<long long > rightPart;
         for(int i=mid+1;i<=ei;i++){
             rightPart.push_back(arr[i]);
         }
         int i=si;
         int j=0;
         int k=0;
         int c1=0;
         int c2=0;
        while(j<leftPart.size() && k<rightPart.size()){
            if(leftPart[j]<=rightPart[k]){
                arr[i]=leftPart[j];
                j++;
            }
            else{
                arr[i]=rightPart[k];
                count+=(leftPart.size()-j);
                k++;
            }
            i++;
        }
        while(j<leftPart.size()){
            arr[i]=leftPart[j];
            j++;
            i++;
        }
        while(k<rightPart.size()){
            arr[i]=rightPart[k];
            k++;
            i++;
        }
        // count+=(c1*c2);
    }
    void MergeSort(long long arr[],long long  n,int si,int ei,long long  &count){
        if(si>=ei){
            return;
        }
        int mid=(si+ei)/2;
        MergeSort(arr,n,si,mid,count);
        MergeSort(arr,n,mid+1,ei,count);
        merge(arr,n,si,mid,ei,count);
    }

    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        int si=0;
        int ei=n-1;
        long long count=0;
        MergeSort(arr,n,si,ei,count);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends