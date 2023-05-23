//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
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
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node * myfunction(int pre[],int preMirror[],int size,int &index,int start,int end){
        if(start>end) return NULL;
        if(index>=size){
            return NULL;
        }
       
        Node * root=new Node(pre[index]);
        index++;
        int find_index=end+1;
        for(int i=start;i<=end;i++){
            if(pre[index]==preMirror[i])
            find_index=i;
        }
        
        root->left=myfunction(pre,preMirror,size,index,find_index,end);
        root->right=myfunction(pre,preMirror,size,index,start+1,find_index-1);
        return root;
    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        int index=0;
        return myfunction(pre,preMirror,size,index,0,size-1);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends