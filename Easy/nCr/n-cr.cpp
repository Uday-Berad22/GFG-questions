//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
#define MOD 1000000007

class Solution{   
public:

long long C(int n, int r)
{
    if (r > n - r)
        r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++)
    {
        ans *= (n - r + i);
        ans %= MOD; // take modulo after multiplication
        ans *= modInverse(i, MOD);
        ans %= MOD; // take modulo after multiplication
    }

    return ans;
}

// Function to compute x^y under modulo m
long long power(long long x, unsigned int y, int m)
{
    if (y == 0)
        return 1;
    long long p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}

// Function to return modulo inverse of a with respect to m using Fermat's little theorem.
// Assumption: m is prime
long long modInverse(long long a, int m)
{
    return power(a, m - 2, m);
}



    long int ncr(int n, int r){
        //complete the function here
        if(n<r) return 0;
        return C(n,r);
    }
    
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, r;
        cin >> n >> r;
        Solution ob;
        cout << ob.ncr(n, r) << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends