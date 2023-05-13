//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int bitMagic(int n, vector<int> &arr) {
        // code 
        int count=0;
        for(int i=0;i<n/2;i++){
            if(arr[i]==arr[n-i-1])
            count++;
        }
        if(count==n) return 0;
        int c1=0,c0=0;
        for(int i=0;i<n/2;i++){
            if(arr[i]==1&&arr[n-i-1]==0){
                c1++;
            }
            
            else if(arr[i]==0&&arr[n-i-1]==1){
                c0++;
            }
        }
        int ans=0;
        int x=c1;
        // if(1c%2==0){
            ans=c0+(c1/2)+(c1%2);
        // }
        c1=0;c0=0;
        int a2=0;
        for(int i=0;i<n/2;i++){
            if(arr[i]==1&&arr[n-i-1]==0){
                c0++;
            }
            
            else if(arr[i]==0&&arr[n-i-1]==1){
                c1++;
            }
        }
        a2=c0+(c1/2)+(c1%2);
        x=x+c1;
        
        return min(min(a2,ans),((x/2)+(x%2)));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.bitMagic(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends