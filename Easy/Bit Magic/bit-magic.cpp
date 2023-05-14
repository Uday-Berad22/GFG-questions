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
        int c1=0,c0=0;
        for(int i=0;i<n/2;i++){
            if(arr[i]==1&&arr[n-i-1]==0){
                c1++;
            }
            
            else if(arr[i]==0&&arr[n-i-1]==1){
                c0++;
            }
        }
        if(c1==0&&c0==0) return 0;
        int ans=c0+(c1/2)+(c1%2);
        int x=c1+c0;
        int a2=c1+(c0/2)+(c0%2);
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