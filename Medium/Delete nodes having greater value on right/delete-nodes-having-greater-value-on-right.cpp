//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
       Node * reverse(Node *head){
        Node *cur=head,*nex=head,*prev=NULL;
        while(nex){
            cur=nex;
            nex=nex->next;
            cur->next=prev;
            prev=cur;
        }
        return cur;
    }
    Node *compute(Node *head)
    {
        head=reverse(head);
        int maxi=INT_MIN;
        Node *p=head,*q=head;
        while(p!=NULL){
            if(p->data<maxi){
                if(p==head){
                    head=p->next;
                    p=head;
                    q=head;
                }
                else{
                    q->next=p->next;
                    p=q->next;
                }
                                
            }
            else
            {
                maxi=max(maxi,p->data);
                q=p;
                p=p->next;
            }
        }
        head=reverse(head);
        return head;
    }

    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends