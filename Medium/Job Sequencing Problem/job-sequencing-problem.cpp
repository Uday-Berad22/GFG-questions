//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
const int N=1e5+10;
bool cmp(Job a,Job b){
    return a.profit>b.profit;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        // map<int,vector<int>> m;
        // // Job v;
        
        // // unordered_map<int,int> mp;
        // for(int i=0;i<n;i++){
        //     if(m[arr[i].dead].size()<arr[i].dead)
        //     {
        //         m[arr[i].dead].push_back(arr[i].profit);
        //         // mp[arr[i].id];
        //     }
        // }
        // vector<int> ans;
        // for(auto a: m){
        //     for(auto b: a.second){
        //         ans.push_back(b);
        //     }
        // }
        //  int count=0;
        //  int c=0;
        // sort(ans.begin(),ans.end());
        // for(int i=0;i<ans.size();i++){
        //     {
        //         c++;
        //     count+=ans[i];
        //   }    
        // }
        // return {c,count} ;
        int help[N+1];
        for(int i=0;i<=N;i++){
            help[i]=1;
        }
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(help[arr[i].dead]!=0){
                help[arr[i].dead]=0;
                sum+=arr[i].profit;
                count++;
            }
            else{
                for(int j=arr[i].dead;j>=1;j--){
                    if(help[j]!=0){
                        sum+=arr[i].profit;
                        count++;
                        help[j]=0;
                        break;
                    }
                }
            }
        }
        return {count,sum};
    } 
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends