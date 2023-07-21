//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/
#define Node node
class Solution
{
    public:
    void reverse_list(node* nex,int k){
        node *cur=NULL,*prev=NULL;

        while(k>0&&nex){
            cur=nex;
            if(nex)
            nex=nex->next;
            if(cur)
            cur->next=prev;
            prev=cur;
            
            k--;
        }
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(k==1){
            // node *cur=NULL,*prev=NULL;
            //     node* nex=head;
            //     // kk=k;
            //         while(nex){
            //       cur=nex;
            //         if(nex)
            //       nex=nex->next;
            //          if(cur)
            //         cur->next=prev;
            //   prev=cur;
            //     //  kk--;
            //  }
             return head;
        }
        Node * s1=NULL,*s2=NULL,*e1=NULL,*e2=NULL;
        Node *p=head,*f_ans=NULL;
        int n=0;
        Node* last;
        while(p!=NULL){
            n++;
            if(p->next==NULL){
                last=p;
            }
            p=p->next;
        }
        int j=0;
        p=head;
        s1=p;
        for(int i=1;(i<=n&&i<k)&&p;i++){
            if(p)
            p=p->next;
        }
        e1=p;
        f_ans=p;
        
        node* q;
        if(p)q=p->next;
        // reverse(s1,k);
        node *cur=NULL,*prev=NULL;
        node* nex=s1;
        int kk=k;
        while(kk>0&&nex){
            cur=nex;
            if(nex)
            nex=nex->next;
            if(cur)
            cur->next=prev;
            prev=cur;
            kk--;
        }
        p=q;
        // cout<<p->data<<endl;
        for(int i=1;i<=n-k&&p;i++){
            if(i%k==1){
                s2=p;
                if(p)
                p=p->next;
            }
            else if(i%k==0){
                e2=p;
                
                if(p)
                q=p->next;
                // cout<<s2->data<<endl;
                // if(e2)
                
                // reverse_list(s2,k);
                 node *cur=NULL,*prev=NULL;
                node* nex=s2;
                kk=k;
                           while(kk>0&&nex){
                         cur=nex;
                           if(nex)
                         nex=nex->next;
                            if(cur)
                           cur->next=prev;
                     prev=cur;
                        kk--;
                    }
                    // cout<<endl;
                    // for(int j=0;j<k;j++){
                    //     cout<<cur->data<<" ";
                    //     cur=cur->next;
                    // }
                    // cout<<endl;
                if(s1){
                s1->next=cur;
               
                }
                s1=s2;
                e1=e2;
                p=q;
                // return f_ans;
            }
            else{
                if(p)
            p=p->next;
            }
        }
        // if(s2)
        // cout<<s2->data<<endl;
        // if(p){
        //     cout<<p->data<<endl;
        // }
        // cout<<kk<<endl;
        if(n%k!=0){
            // cout<<"Aloo"<<endl;
            e2=last;
        
             node *cur=NULL,*prev=NULL;
                node* nex=s2;
                kk=k;
                    while(kk>0&&nex){
                  cur=nex;
                    if(nex)
                  nex=nex->next;
                     if(cur)
                    cur->next=prev;
              prev=cur;
                 kk--;
             }
                if(s1){
                s1->next=e2;
                    
                }
                s1=e2;
                e1=s2;
                p=q;
        }
        return f_ans;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends