//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
#define TreeNode Node 
class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        vector<int> inorder,postorder;
        for(int i=0;i<n;i++){
            inorder.push_back(in[i]);
            postorder.push_back(post[i]);
        }
        return buildTree1(inorder,postorder);
    }
    TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }

        // Create a hashmap to store inorder indices
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderIndexMap);
    }

    TreeNode* buildTreeHelper(vector<int>& inorder, int inorderStart, int inorderEnd,
                              vector<int>& postorder, int postorderStart, int postorderEnd,
                              unordered_map<int, int>& inorderIndexMap) {
        if (inorderStart > inorderEnd || postorderStart > postorderEnd) {
            return nullptr;
        }

        int rootValue = postorder[postorderEnd];
        TreeNode* root = new TreeNode(rootValue);

        int inorderIndex = inorderIndexMap[rootValue];
        int leftSize = inorderIndex - inorderStart;

        root->left = buildTreeHelper(inorder, inorderStart, inorderIndex - 1,
                                     postorder, postorderStart, postorderStart + leftSize - 1,
                                     inorderIndexMap);
        root->right = buildTreeHelper(inorder, inorderIndex + 1, inorderEnd,
                                      postorder, postorderStart + leftSize, postorderEnd - 1,
                                      inorderIndexMap);

        return root;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends