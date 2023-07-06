//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int v[], int low, int high)
    {
        if(low<high)
        {
            int p_index=partition(v,low,high);
            quickSort(v,low,p_index-1);
            quickSort(v,p_index+1,high);
        }
    }
    
    public:
    int partition (int v[], int low, int high)
    {
         int pivot=v[high];
        int i=low-1;
        int temp;
        for(int j=low;j<high;j++)
        {
            if(v[j]<pivot)
            {
                i++;
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
        i++;
        temp=v[i];
        v[i]=pivot;
        v[high]=temp;
        return i;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends