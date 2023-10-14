//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
class Solution
{
    vector<int> ans;
    // unordered_set<int> s;
    unordered_map<pair<Node*,Node*>,int,hash_pair> m;
    public:
    //Function to find the nodes that are common in both BST.
    void fun(Node *root1, Node *root2){
        if(root1==NULL||root2==NULL) return;
        // m[{root1,root2}]++;
        fun(root1->left,root2->left);
        if(root1->data==root2->data){
            ans.push_back(root1->data);
        //     if(m[{root1->left,root2->left}]==0)
        //     fun(root1->left, root2->left);
        //     if(m[{root1->right,root2->right}]==0)
            fun(root1->right, root2->right);
            return;
        }
        else if(root1->data<root2->data){
            fun(root1->right, root2);
        }
        else{
             fun(root1, root2->right);
        }
        // else if(root1->data>root2->data){
        //     if(m[{root1->left,root2}]==0)
        //     fun(root1->left, root2);
        //     if(m[{root1,root2->right}]==0)
        //     fun(root1, root2->right);
        // }
        // else{
        //     if(m[{root1,root2->left}]==0)
        //     fun(root1, root2->left);
        //     if(m[{root1->right,root2}]==0)
        //     fun(root1->right, root2);
        // }
    }
    void func(vector<int> &a,Node *root){
        if(root==NULL) return;
        func(a,root->left);
        a.push_back(root->data);
        func(a,root->right);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
        // fun(root1,root2);
        // // for(auto &a: s){
        // //     ans.push_back(a);
        // // }
        // sort(ans.begin(),ans.end());
        // // s.clear();
        vector<int> a,b;
        func(a,root1);
        func(b,root2);
        // unordered_map<int,int> mp;
        int i=0;
        int j=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]<b[j]){
                i++;
            }
            else{
                j++;
            }
        }
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
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }

	return 1;
}
// } Driver Code Ends