//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}

// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    // Code here
    int n=str.size();
    for(int i=1;i<=6;i++){
        vector<int> v;
        int x=i;
        for(int j=0;j<n;){
            string temp= str.substr(j,x);
            int num=stoi(temp);
            string temp2=to_string(num+1);
            if(v.size()>0 && num<v.back()){
                x++;
                 temp= str.substr(j,x);
                 num=stoi(temp);
            }
            j+=x;
            v.push_back(num);
        }
        int count=0;
        int k=0;
        for(int j=0;j<v.size()-1;j++){
            if(v[j+1]<=v[j]){
                count=INT_MAX;
                break;
            }
            if((v[j+1]-v[j])==2){
                k=j;
                count++;
            }
            else if((v[j+1]-v[j])>2){
                count=INT_MAX;
                break;
            }
        }
        if(count==1){
            return v[k]+1;
        }
    }
    

    return -1;
    
}