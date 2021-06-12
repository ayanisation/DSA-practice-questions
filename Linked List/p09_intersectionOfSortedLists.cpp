#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2)
{
    unordered_set<int>s;
    while(head1){
        s.insert(head1->data);
        head1=head1->next;
    }
    Node* h;
    Node* a;
    int c=1;
    while(head2){
        auto it = s.find(head2->data);
        if(it!=s.end()){
            if(c){
                h=new Node(*it);
                a=h;
                c=0;
            }
            else{
                a->next=new Node(*it);
                a=a->next;
            }
            s.erase(it);
        }
        head2=head2->next;
    }
    return h;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

