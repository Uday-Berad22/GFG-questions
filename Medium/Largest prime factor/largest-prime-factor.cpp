//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

const int Ni=1e5+10;
vector<bool> is_prime(Ni,true);
vector<int> highest_prime(Ni,0);
vector<int> lowest_prime(Ni,0);
class Solution{
public: 
    long long int largestPrimeFactor(int n){
        is_prime[0]=is_prime[1]=false;
     for(int i=2;i<Ni;i++){
        if(is_prime[i]==true){
            highest_prime[i]=lowest_prime[i]=i;
            for(int j=2*i;j<Ni;j+=i){
                is_prime[j]=false;
                if(lowest_prime[j]==0){
                    lowest_prime[j]=i;
                }
                highest_prime[j]=i;
            }
        }
    }
        return highest_prime[n];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends