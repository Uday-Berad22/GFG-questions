//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int a[], int n)
    {
        // code here
        vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
            continue;
        int x = max(0, i - a[i]);
        int y = min(n - 1, i + a[i]);
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int ans = 1;
    int j = 0;
    for (int i = 0; i < v.size(); i++)
    {
        j = i;
        if (v[i].first != 0)
        {
            break;
        }
    }
    if (v.size() == 0)
        return -1;
    if (v[0].second == n - 1 && v[0].first == 0)
        return 1;
    if (j == 0)
    {

        return -1;
    }
    auto prev = v[j - 1];
    if (v[j].first == 0)
    {
        prev = v[j];
    }
    // cout << prev.first << " " << prev.second << " ";
    for (int i = j; i < v.size(); i++)
    {
        // cout << "[" << v[i].first << " " << v[i].second << " ] ";
        if (prev.second == n - 1)
            return ans;
        if (v[i].first > prev.second + 1)
        {
            return -1;
        }
        if (v[i].second < prev.second)
        {
            continue;
        }
        if (v[i].second == prev.second)
        {
            continue;
        }
        if (v[i].first <= prev.first + 1 && prev.first != 0)
        {
            prev.second = v[i].second;
            // prev = v[i];
        }
        else
        {
            ans++;
            // cout << "[" << prev.first << " " << prev.second
            //      << " ";
            prev.first = prev.second;
            prev.second = v[i].second;
            // // prev = v[i];
            // cout << prev.first << " " << prev.second << "]"
            //      << " ";
        }
    }
    if (prev.second != n - 1)
        return -1;
    return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends