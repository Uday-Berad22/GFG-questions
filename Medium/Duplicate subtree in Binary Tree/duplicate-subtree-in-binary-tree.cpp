//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
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
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/
#define righ right
class Solution {
    unordered_map<string,int> m;
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int fun(Node *root,bool &ans){
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return root->data;
        // cout<<"HELLO"<<endl;
        if((root->left!=NULL&&root->right!=NULL)&&(root->left->left==NULL&&root->left->right==NULL)&&(root->right->right==NULL&&root->right->left==NULL)){
            string temp;
            int x=fun(root->left,ans);
            int y=fun(root->right,ans);
            int z=root->data;
            temp.push_back('0'+x);
            temp.push_back('0'+y);
            temp.push_back('0'+z);
            m[temp]++;
            // cout<<temp<<endl;
            if(m[temp]>1) ans=true;
        }
        else if((root->left!=NULL&&root->righ==NULL)&&root->left->left==NULL&&root->left->right==NULL){
            string temp;
            int x=fun(root->left,ans);
            // int y=fun(root->right);
            int z=root->data;
            temp.push_back('0'+x);
            temp.push_back('-');
            temp.push_back('0'+z);
            // cout<<temp<<endl;
            m[temp]++;
            if(m[temp]>1) ans=true;
        }
        else if((root->left==NULL&&root->righ!=NULL)&&root->right->left==NULL&&root->right->right==NULL){
            string temp;
            // int x=fun(root->left);
            int y=fun(root->right,ans);
            int z=root->data;
            temp.push_back('-');
            temp.push_back('0'+y);
            temp.push_back('0'+z);
            // cout<<temp<<endl;
            m[temp]++;
            if(m[temp]>1) ans=true;
        }
        else{
            fun(root->left,ans);
            fun(root->right,ans);
        }
        return 0;
    }
    int dupSub(Node *root) {
        bool ans=false;
        m.clear();
        fun(root,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}
// } Driver Code Ends