// driver

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

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

struct Node* reverseList(struct Node *head)
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
    return head;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node* f = reverseList(first);
    Node* s = reverseList(second);
    Node* h = new Node((f->data+s->data)%10);
    Node* t = h;
    int c = (f->data+s->data)/10;
    f = f->next;
    s = s->next;
    while(f!=NULL||s!=NULL)
    {
        if(f==NULL)
        {
            t->next = new Node((s->data+c)%10);
            c = (s->data+c)/10;
            s = s->next;
        }
        else if(s==NULL)
        {
            t->next = new Node((f->data+c)%10);
            c = (f->data+c)/10;
            f = f->next;
        }
        else
        {
            t->next = new Node((f->data+s->data+c)%10);
            c = (f->data+s->data+c)/10;
            f = f->next;
            s = s->next;
        }
        t = t->next;
    }
    if(c>0)
    {
        t->next = new Node(c);
        t = t->next;
    }
    Node* head = reverseList(h);
    return head;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

