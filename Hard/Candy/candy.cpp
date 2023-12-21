//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
    
        if (N == 1)
        return 1;
    vector<int> v;
    int n = N;
    vector<int> ans(N, 0);
    int last = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            if (ratings[i + 1] > ratings[i])
            {
                last = i;
            }
            ans[i] = 1;
        }

        else if (i == n - 1)
        {
            if (ratings[i - 1] >= ratings[i])
            {

                ans[i] = 1;
            }
            else
            {
                ans[i] = ans[i - 1] + 1;
            }
        }
        else
        {
            if (ratings[i - 1] > ratings[i] && ratings[i + 1] > ratings[i])
            {
                last = i;
            }
            if (ratings[i - 1] >= ratings[i])
            {
                ans[i] = 1;
            }
            else
            {
                ans[i] = ans[i - 1] + 1;
            }
        }
    }
    last = N - 1;
    for (int i = N - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            if (ratings[i + 1] >= ratings[i])
            {
                ans[i] = max(ans[i], 1);
            }
            else
            {
                ans[i] = max(ans[i], ans[i + 1] + 1);
            }
        }
        else if (i == n - 1)
        {
            if (ratings[i - 1] > ratings[i])
            {
                last = i;
            }
        }
        else
        {
            if (ratings[i - 1] > ratings[i] && ratings[i + 1] > ratings[i])
            {
                last = i;
            }
            if (ratings[i + 1] >= ratings[i])
            {
                ans[i] = max(ans[i], 1);
            }
            else
            {
                ans[i] = max(ans[i], ans[i + 1] + 1);
            }
        }
        // ans[i] = max(ans[i], (last - i) + 1);
    }
    int sum = accumulate(ans.begin(), ans.end(), 0);
    return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends