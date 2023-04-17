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
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        // sort(A.begin(),A.end());
        // sort(B.begin(),B.end());
        long long  s1=accumulate(A.begin(),A.end(),0);
        long long  s2=accumulate(B.begin(),B.end(),0);
        if(s1!=s2) return -1;
        vector<int> c,d,h,g;
        unordered_map<int,int> m;
        for(int i=0;i<B.size();i++){
            m[B[i]]++;
        }
        long long ec=0,oc=0,ecb=0,ocb=0,ans=0;
        for(int i=0;i<A.size();i++){
            if(m[A[i]]==0){
                if(A[i]%2==0){
                    ec++;
                    c.push_back(A[i]);
                }
                else{
                    oc++;
                    d.push_back(A[i]);
                }
                
            }
            else{
                m[A[i]]--;
            }
        }
        for(int i=0;i<B.size();i++){
            if(m[B[i]]!=0){
                if(B[i]%2==0){
                    ecb++;
                    h.push_back(B[i]);
                }
                else{
                    ocb++;
                    g.push_back(B[i]);
                }
                m[B[i]]--;
            }
        }
        // for(auto a: m){
        //     if(a.first%2==0){
        //       int  k=a.second;
        //         ecb+=a.second;
        //         while(k--)
        //         h.push_back(a.first);
        //     }
        //     else{
        //         ocb+=a.second;
        //         int  k=a.second;
        //         // ecb+=a.second;
        //         while(k--)
        //         g.push_back(a.first);
        //     }
        // }
        sort(g.begin(),g.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        sort(h.begin(),h.end());
        if(ecb!=ec|| ocb!=oc){
            return -1;
        }
        for(int i=0;i<c.size();i++){
            ans=ans+abs(c[i]-h[i]);
        }
        for(int i=0;i<g.size();i++){
            ans=ans+abs(d[i]-g[i]);
        }
        return ans/4;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends A[3] = 6 + 2 + 2 = 10