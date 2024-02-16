//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
      void solve ( int ind , int k , string &res , string str )
    {
        if(k == 0 || ind == str.size())
        {
            return ;
        }
        
        bool flag = true ;// to indicate if we have done swapping or not 
        
        for(int i = str.size() - 1 ; i > ind ; i--)
        {
            if(str[i] > str[ind])
            {
                swap(str[i] , str[ind]);
                k--;
                res = max(res , str) ;
                flag = false ;
                solve(ind+1 , k , res , str) ;
                swap(str[i],str[ind]);
                k++;
            }
        }
        
        if(flag == true)
        {
            //=> no swapping done 
            solve(ind+1 , k , res , str);
        }
    }
    
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        //concept used :- backtracking 
        string res = str ;
        solve(0 , k , res , str ) ;
        
        return res ;
    }


};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends