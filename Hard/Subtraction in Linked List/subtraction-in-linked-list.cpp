//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:


    Node * reverse(Node *cur){
        Node *prev=NULL,*nex=cur;
        while(nex!=NULL){
            cur=nex;
            nex=nex->next;
            cur->next=prev;
            prev=cur;
        }
        return cur;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        int count1=0;
        int count2=0;
        Node* h1=head1;
        Node* h2=head2;
        while(h1!=NULL){
            if(h1->data==0 && count1==0){
                head1=h1->next;
            }
            else{
                count1++;
            }
            h1=h1->next;
        }
         while(h2!=NULL){
            if(h2->data==0 && count2==0){
                head2=h2->next;
            }
            else{
                count2++;
            }
            h2=h2->next;
        }
        if(count1==0&& count2==0){
            Node* temp= new Node(0);
            return temp;
        }
        
        if(count1==0){
            return head2;
        }
        if(count2==0){
            return head1;
        }
        if(count1==count2){
            Node *x1=head1;
            Node *x2=head2;
            while(x1!=NULL && x1->data==x2->data){
                x1=x1->next;
                x2=x2->next;
            }
            if(x1==NULL && x2==NULL){
                x1=new Node(0);
                return x1;
            }
            if(x2->data> x1->data){
                Node *temp= head1;
                head1=head2;
                head2=temp;
            }
        }
        if(count2>count1){
            Node * temp=head1;
            head1=head2;
            head2=temp;
        }
        head1=reverse(head1);
        head2=reverse(head2);
        h1=head1;
        h2=head2;
        while(head1!=NULL){
            int data2=0;
            if(head2!=NULL){
                data2=head2->data;
            }
            int sub=(head1->data)-(data2);
            if(sub<0){
                if(head1->next==NULL){
                    Node *temp= new Node(-1);
                    head1->next=temp;
                }
                else{
                    head1->next->data=head1->next->data-1;
                }
                head1->data=10+sub;
            }
            else{
                head1->data=sub;
            }
            head1=head1->next;
            if(head2!=NULL)
            head2=head2->next;
        }
        head1=reverse(h1);
        if(count1>1){
            while(head1->next!=NULL&& head1->data==0){
                head1=head1->next;
            }
           
        }
        return head1;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends