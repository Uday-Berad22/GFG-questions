//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
unordered_map<Node*,int> m;
class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    int height(Node *root){
        if(root==NULL) return 0;
        int x;
        // if(m.find(root->left)!=m.end())x=m[root->left];
        x=height(root->left);
        int y;
        y=height(root->right);
        return max(x,y)+1;
    }
    int Balance_factor(Node *root){
        if(root==NULL) return 0;
        return height(root->left)-height(root->right);
    }
    Node * buildBalancedTreeR(Node *root){
        if(root==NULL) return NULL;
        if(height(root->left)-height(root->right)>1&&Balance_factor(root->left)>0){
            Node *temp=root->left->right;
            Node *p=root->left;
            root->left->right=root;
            root->left=temp;
            return p;
        }
        if(height(root->left)-height(root->right)<-1&&Balance_factor(root->right)<0){
            Node *p=root->right;
            root->right=p->left;
            p->left=root;
            return p;
        }
        if(height(root->left)-height(root->right)<-1&&Balance_factor(root->right)>0){
            Node *p=root->right->left;
            Node *q=root->right;
            root->right=p->left;
            p->left=root;
            q->left=p->right;
            p->right=q;
            return p;
        }
         if(height(root->left)-height(root->right)>1&&Balance_factor(root->left)<0){
            Node *p=root->left->right;
            Node *q=root->left;
            q->right=p->left;
            root->left=p->right;
            p->right=root;
            p->left=q;
            return p;
        }
        return root;
    }
    Node* insert(Node *a,Node *root){
        if(root==NULL){
            return a;
        }
        if((root->data)<(a->data)){
            root->right=insert(a,root->right);
        }
        else{
            root->left=insert(a,root->left);
        }
        return buildBalancedTreeR(root);
    }
    // void inorder(Node *root,vector<Node*> &v){
    //     if(root==NULL) return;
    //     inorder(root->left,v);
    //     v.push_back(root);
    //     inorder(root->right,v);
    // }
    
    // Node* buildBalancedTree(Node* root)
    // {
    //   vector<Node*> v;
    //   inorder(root,v);
    //   root=NULL;
    //   for(auto &a: v){
    //     a->left=NULL;
    //     a->right=NULL;
    //     root=insert(a,root);
    //   }
    //   return root;
    // }
     void inorder(Node* root,vector<int>&nodes){
        if(root==NULL)return;
        inorder(root->left,nodes);
        nodes.push_back(root->data);
        inorder(root->right,nodes);
    }
    Node *createhbst(int left,int right,vector<int>&inorder){
        if(left>right)return NULL;
        int mid=(left+right)/2;
        Node* newroot=new struct Node(inorder[mid]);
        newroot->left=createhbst(left,mid-1,inorder);
        newroot->right=createhbst(mid+1,right,inorder);
        return newroot;
    }
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
        vector<int>nodes;
        inorder(root,nodes);
        return createhbst(0,nodes.size()-1,nodes);
    }
};


//{ Driver Code Starts.

Node* insert(struct Node* node, int key){
	if (node == NULL) return new Node(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	return node;
}

void preOrder(Node* node)
{
	if (node == NULL)return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int height(struct Node* node) 
{
  if (node==NULL) 
    return 0;
  int lDepth = height(node->left);
  int rDepth = height(node->right);
  if (lDepth > rDepth) 
    return(lDepth+1);
  else 
    return(rDepth+1);
} 
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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* buildBalancedTree(Node* root);

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        struct Node *root = NULL;
        int n, temp;
        string tree;
        getline(cin,tree);
        root = buildTree(tree);
        // cout<<height(root)<<endl;
        Solution obj;
        root = obj.buildBalancedTree(root);
        cout<<height(root)<<endl;
    }
	return 0;
}

// } Driver Code Ends