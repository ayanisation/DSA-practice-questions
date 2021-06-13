#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

struct Node* reverseList(struct Node *x)
{
    Node *a,*b,*n;
    a = x;
    b = NULL;
    while(a!=NULL)
    {
        n = a->next;
        a->next = b;
        b = a;
        a = n;
    }
    x = b;
    return x;
}
bool isPalindrome(Node *head)
{
    Node *h = head;
    Node *n = new Node(h->data);
    Node *t = n;
    h = h->next;
    while(h!=NULL)
    {
        t->next = new Node(h->data);
        t = t->next;
        h = h->next;
    }
    Node *r = reverseList(n);
    while(head!=NULL)
    {
        if(head->data!=r->data)
        return false;
        r = r->next;
        head = head->next;
    }
    if(head==NULL)
    return true;
}

int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}


