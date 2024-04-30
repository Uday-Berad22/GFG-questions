//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* p, struct Node* q)
    {
        struct Node* r=NULL,*prev=NULL,*cur=NULL,*nex=NULL;
        nex=p;
        while(nex!=NULL)
        {
            cur=nex;
            nex=nex->next;
            cur->next=prev;
            prev=cur;
        }
        p=cur;
        nex=prev=cur=NULL;
        nex=q;
        while(nex!=NULL)
        {
            cur=nex;
            nex=nex->next;
            cur->next=prev;
            prev=cur;
        }
        q=cur;
        nex=prev=cur=NULL;
        int c=0;
        while(p!=NULL||q!=NULL)
        {
            int a=0,b=0;
            if(p!=NULL)
            {
                a=p->data;
                p=p->next;
            }
            if(q!=NULL)
            {
                b=q->data;
                q=q->next;
            }
            if(r==NULL)
            {
                r=new Node(0);
                r->data=(a+b+c)%10;
                c=(a+b+c)/10;
                r->next=NULL;
                cur=r;
            }
            else
            {
                prev=new Node(0);
                prev->data=(a+b+c)%10;
                c=(a+b+c)/10;
                prev->next=NULL;
                cur->next=prev;
                cur=prev;
            }
        }
        if(c>0)
        {
            nex=new Node(0);
            nex->data=c;
            cur->next=nex;
            nex->next=NULL;
        }
         nex=prev=cur=NULL;
         nex=r;
        while(nex!=NULL)
        {
            cur=nex;
            nex=nex->next;
            cur->next=prev;
            prev=cur;
        }
        r=cur;
        while(r!=NULL && r->data==0){
            r=r->next;
        }
        if(r==NULL){
            r=new Node(0);
            return r;
        }
        return r;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends