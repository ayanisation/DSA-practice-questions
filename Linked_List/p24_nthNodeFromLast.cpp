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

int getNthFromLast(Node *head, int n)
{
       Node *h = head;
       int x = 0;
       while(h!=NULL)
       {
           h=h->next;
           x+=1;
       }
       if(x<n)
       return -1;
       n = x-n;
       h = head;
       for(int i=0;i<n;i++)
       h = h->next;
       return h->data;
}

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}


