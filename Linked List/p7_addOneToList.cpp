//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node *a,*b,*n;
        a = head;
        b = NULL;
        while(a!=NULL)
        {
            n = a->next;
            a->next = b;
            b = a;
            a = n;
        }
        head = b;
        int c=1;
        Node *h=head;
        while(h->next){
            int x = h->data+c;
            h->data = x%10;
            c=x/10;
            h=h->next;
        }
        if(c){
            if(h->data+1==10){
                h->data = 0;
                h->next = new Node(1);
                h=h->next;
            }
            else
            h->data=h->data+1;
        }
        a = head;
        b = NULL;
        while(a!=NULL)
        {
            n = a->next;
            a->next = b;
            b = a;
            a = n;
        }
        head = b;
        return head;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
