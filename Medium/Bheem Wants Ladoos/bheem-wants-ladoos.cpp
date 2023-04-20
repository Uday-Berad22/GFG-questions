//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/


unordered_map<Node *,Node *>  m;
int t;
unordered_map<int,int> m1;
class Solution{

    public:
    void fun(Node *p,int count,int &ans){
        if(p==NULL) return ;
    
        
        // cout<<p->data<<endl;
        // if(m[p]!=NULL)/
        if(m1[p->data]==0){
            // cout<<p->data<<endl;
        ans+=p->data;
        m1[p->data]++;
        }
        if(count==t) return ;
        Node *t1=p->left,*t2=p->right,*t3=m[p];
        // m[p]=NULL;
        // if(m[p->left]!=NULL){
        fun(t1,count+1,ans);
        // }
        // if(m[p->right]!=NULL){
        fun(t2,count+1,ans);
        // }
        
        fun(t3,count+1,ans);
        // }
    }
    int ladoos(Node* root, int home, int k)
    {
        m.clear();
        m1.clear();
        t=k;
        queue<Node *> q;
        q.push(root);
        Node *temp=NULL;
        while(!q.empty()){
            Node *p=q.front();
            if(p->data==home)
            temp=p;
            q.pop();
            if(p->left){
                q.push(p->left);
                m[p->left]=p;
            }
            if(p->right){
                q.push(p->right);
                m[p->right]=p;
            }
        }
        int ans=0;
        fun(temp,0,ans);
        return ans;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends