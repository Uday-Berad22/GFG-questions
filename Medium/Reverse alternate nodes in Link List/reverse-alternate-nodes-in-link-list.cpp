//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node *reverse(Node *p){
        Node *cur=p;
        Node * nex=p;
        Node *prev=NULL;
        while(nex!=NULL){
            cur=nex;
            nex=nex->next;
            cur->next=prev;
            prev=cur;
        }
        return cur;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        Node * p;
        Node *dummy=new Node(-1);
        p=odd;
        if(odd->next==NULL) return;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=dummy;
        p=odd;
        Node* temp=odd;
        while(p!=NULL&&p->data!=-1){
            Node *q=p->next;
            if(q->data==-1){
                p=p->next;
                temp=temp->next;
                break;
            }
            p->next=q->next;
            dummy->next=q;
            dummy=q;
            q->next=NULL;
            temp=p;
            p=p->next;
        }
        temp->next=p->next;
        p=p->next;
        temp->next=reverse(temp->next);
       
        return;
    }
};




//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends