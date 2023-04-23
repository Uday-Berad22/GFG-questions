//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        stack<int> s;
        int n=arr.size();
        vector<int> ans(n,-1);
    
        for(int i=0;i<arr.size();i++){
            if(s.empty()){
            ans[i]=-1;
            s.push(i);
            }
            else{
                if(arr[s.top()]<arr[i]){
                    ans[i]=(s.top());
                    s.push(i);
                }
                else{
                    
                    while(!s.empty()){
                        if(arr[s.top()]<arr[i]){
                            ans[i]=s.top();
                            break;
                        }
                        s.pop();
                    }
                    s.push(i);
                }
            }
        }
        // for(int i=0;i<ans.size();i++)
        // cout<<ans[i]<<" ";
        // cout<<endl;
        stack<int> s2;
        for(int i=n-1;i>=0;i--){
            if(s2.empty()){
             s2.push(i);
            }
            else{
                if(arr[s2.top()]<arr[i]&&ans[i]==-1){
                    ans[i]=s2.top();
                }
                else if(arr[s2.top()]<arr[i]){
                    if(abs(i-ans[i])>abs(s2.top()-i))
                    ans[i]=s2.top();
                    else if(abs(i-ans[i])==abs(s2.top()-i)){
                        if(arr[s2.top()]<arr[ans[i]])
                        ans[i]=s2.top();
                    }
                    
                }
                else{
                    while(!s2.empty()){
                        if(arr[s2.top()]<arr[i]){
                            if(ans[i]==-1){
                                ans[i]=s2.top();
                                break;
                            }
                           if(abs(i-ans[i])>abs(s2.top()-i))
                         ans[i]=s2.top();
                         else if(abs(i-ans[i])==abs(s2.top()-i)){
                        if(arr[s2.top()]<arr[ans[i]])
                        ans[i]=s2.top();
                    }
                            break;
                        }
                        s2.pop();
                    }
                    if(!s2.empty()){
                    if(abs(i-ans[i])>abs(s2.top()-i))
                    ans[i]=s2.top();
                    else if(abs(i-ans[i])==abs(s2.top()-i)){
                        if(arr[s2.top()]<arr[ans[i]])
                        ans[i]=s2.top();
                    }
                    }
                    // s2.push(i);
                }
                s2.push(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends