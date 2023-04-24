//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        //  // Your logic here
         int x=log2(n)+1;
         unordered_map<int,int> m;
         if(n==1)
         return 1;
         if(n==2)
         return 2;
         if(n==3)
         return 4;
         m[1]=1;
         m[3]=4;
         for(int i=3;i<=x;i++){
             int y=1<<i;
             int size=1<<(i-1);
             int k=1<<(i-1);
            m[y-1]=((size*(i-1))/2)+size+m[k-1];
         }
        //  cout<<m[7]<<" "<<m[15]<<endl;
         int fans=0;
         int  z=1<<(((int)log2(n)));
         int stop=(int)log2(n);
        //  cout<<z<<endl;/
        // cout<<z<<endl;
       
         int diff=n-z+1;
         int bro=0;
        //  if(__builtin_popcount(n)==1||__builtin_popcount(n+1)==1){
        //      return m[z-1]+(__builtin_popcount(n)==1?1:0);
        //  }
        // cout<<m[z-1]<<endl;
         for(int i=0;i<stop;i++){
             int ans=diff/pow(2,i);
             ans=ans/2;
             ans=ans*pow(2,i);
             
             int flag=0;
             if(1&(n>>i)){
                 int b=pow(2,i);
                 flag=diff%b;
             }
            //  cout<<flag<<"--"<<endl;
             ans=ans+flag;
            //  cout<<ans<<endl;
             fans+=ans;
             bro=1;
            //  cout<<fans<<" kkk"<<endl;
         } 
        //  cout<<(1<<(stop))<<" ("<<endl;
         if(bro==1)
         fans+=diff;
        //  cout<<bro<<endl;
        //  cout<<z<<endl;
        //  cout<<m[z-1]<<endl;
        return fans+m[z-1];
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends