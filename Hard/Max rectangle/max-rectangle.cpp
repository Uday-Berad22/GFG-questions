//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
       int getMaxArea(int a[], int n)
    {
        vector<int> ps(n), ns(n);
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && a[st.top()]>=a[i])
                st.pop();
                
            if(st.empty())
                ps[i] = -1;
            else
                ps[i] = st.top();
                
            st.push(i);
        }
        st = stack<int>();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && a[st.top()]>=a[i])
                st.pop();
                
            if(st.empty())
                ns[i] = n;
            else
                ns[i] = st.top();
                
            st.push(i);
        }
        
        int maxArea = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int area = (ns[i] - ps[i] - 1) * a[i];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        int cur[m] = {0};
        int area = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] == 1)
                    cur[j] += 1;
                else 
                    cur[j] = 0;
            }
            int currArea = getMaxArea(cur, m);
            area = max(currArea, area);
        }
        
        return area;
    }

};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends