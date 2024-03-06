//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    void precomputeFunction(vector<int> &precomputeArr, string &s2)
{
    int len = 0;
    int index = 1;
    int m = s2.size();
    while (index < m)
    {
        if (s2[len] == s2[index])
        {
            len++;
            precomputeArr[index] = len;
            index++;
        }
        else
        {
            if (len != 0)
            {
                len = precomputeArr[len - 1];
            }
            else
            {
                precomputeArr[index] = 0;
                index++;
            }
        }
    }
}

vector<int> search1(string s2, string s1)
{
    int count = 0;
    int n = s1.size();
    int m = s2.size();
    vector<int> precomputeArr(m, 0);

    precomputeFunction(precomputeArr, s2);
    int i = 0;
    int j = 0;
    vector<int> ans;
    int c = 0;
    int round = 0;
    while (i<n)
    {

        if (s1[i ] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = precomputeArr[j - 1];
            }
        }

        if (j == m)
        {
            count++;
         

            ans.push_back((i - j+1));

            j = precomputeArr[j - 1];
        }
    }
    return ans;
}
        vector <int> search(string pattern, string text)
        {
            //code here.
            return search1(pattern, text);
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends