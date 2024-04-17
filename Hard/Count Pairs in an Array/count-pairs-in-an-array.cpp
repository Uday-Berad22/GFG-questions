//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    void merge(int arr[],int n,int si,int mid,int ei,int &count){
         vector<int> leftPart;
         for(int i=si;i<=mid;i++){
             leftPart.push_back(arr[i]);
         }
         vector<int> rightPart;
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
    void MergeSort(int arr[],int n,int si,int ei,int &count){
        if(si>=ei){
            return;
        }
        int mid=(si+ei)/2;
        MergeSort(arr,n,si,mid,count);
        MergeSort(arr,n,mid+1,ei,count);
        merge(arr,n,si,mid,ei,count);
    }
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        for(int i=0;i<n;i++){
            arr[i]*=i;
        }
        int si=0;
        int ei=n-1;
        int count=0;
        MergeSort(arr,n,si,ei,count);
        return count;
    }
};

// 0 0 20 6 16 5 36

    //   3  1 1 


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends