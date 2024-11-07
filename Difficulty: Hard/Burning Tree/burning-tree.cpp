//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        //level order and also find the pointer of target
        unordered_map<Node*,Node*> parent;
        Node* targetNode=NULL;
        queue<Node*> q;
        int totalTime=0;
        parent[root]=NULL;
        q.push(root);
        while(0!= q.size()){
            Node* currNode=q.front();
            q.pop();
            if(currNode->data==target) targetNode=currNode;
            
            if(NULL != currNode->left){
                parent[currNode->left]=currNode;
                q.push(currNode->left);
            }
            
            if(NULL != currNode->right){
                parent[currNode->right]=currNode;
                q.push(currNode->right);
            }
            
            
        }
        
        if(NULL == targetNode) return -1;
        
        q.push(targetNode);

        while(0!= q.size()){
            int qsiz=q.size();
            for(int i=0;i<qsiz;i++){
                Node* currNode=q.front();
                q.pop();
               
                
                if(NULL != currNode->left && NULL != parent[currNode->left]){
                    parent[currNode->left]=NULL;
                    q.push(currNode->left);
                }
                
                if(NULL != currNode->right && NULL != parent[currNode->right]){
                    parent[currNode->right]=NULL;
                    q.push(currNode->right);
                }
                
                if(NULL != parent[currNode]){
                    q.push(parent[currNode]);
                    parent[currNode]=NULL;
                }
            }
            totalTime++;
        }
        return totalTime-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    
cout << "~" << "\n";
}


    return 0;
}

// } Driver Code Ends