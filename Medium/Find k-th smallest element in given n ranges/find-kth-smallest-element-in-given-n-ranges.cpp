//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&q, int qi, vector<int>queries){
        vector<pair<int,int>> v;
        vector<int> ans;
        for(int i=0;i<q.size();i++){
            v.push_back({q[i][0],q[i][1]});
        }
        sort(v.begin(),v.end(),cmp);
        int j=0;
        vector<pair<int,int>> vp;
        for(int i=0;i<v.size();i++){
            if(vp.size()==0){
                vp.push_back(v[i]);
                j++;
            }
            else{
        
                if(i>=1&&vp[j-1].second>=v[i].first){
                    vp[j-1].second=max(vp[j-1].second,v[i].second);
                }
                else{
                    vp.push_back(v[i]);
                    j++;
                }
            }
        }
        
        for(int i=0;i<queries.size();i++){
            int count=0;
            int remain=0;
            int a=-1;
            for(int j=0;j<vp.size();j++){
                remain=queries[i]-count;
                count=count+((vp[j].second-vp[j].first)+1);
                if(count>=queries[i]){
                    a=(vp[j].first)+remain-1;
                    break;
                }
            }
            ans.push_back(a);
        }
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends