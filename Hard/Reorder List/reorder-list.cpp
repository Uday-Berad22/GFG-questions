//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
   Node* reverse(Node *cur,Node *prev){
        // 3 2  
        // null 
        // prev=NULL;
        Node* nex=cur;
        while(cur!=NULL){
            nex=nex->next;
            
            cur->next=prev;
            // cout<<cur->data<<endl;
            // break;
            prev=cur;
            cur=nex;
        }
        return prev;
    }
    void reorderList(Node* head) {
        // Your code here
        Node *p=head;
        int count=0;
        while(p!=NULL){
            count++;
            p=p->next;
        }
        if(count<=2){
            return;
        }
        p=head;
        for(int i=0;i<(count-1)/2;i++){
            p=p->next;
        }
        Node *r =head->next;
        Node * q=reverse(p->next,p);
        
        // cout<<q->data<<endl;
        head->next=NULL;
        Node * s=q->next;
        // cout<<s->data<<endl;
        p->next=NULL;
        p=head;
        int i=0;
        while(i<((count+1)/2) && p!=NULL && q!=NULL){
            // if(p==q){
            //     break;
            // }
            p->next=q;
            q->next=r;
            p=r;
            q=s;
            if(r==NULL){
                break;
            }
            r=r->next;
            s=s->next;
            i++;
        }
        return;
        
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends