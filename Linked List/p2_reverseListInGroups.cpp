#include <bits/stdc++.h>
#include <fstream>
typedef long long int ll;
#define nitro ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pi 3.1415926535897932384626
#define loop(i, a, b, c) for (i = a; i < b; i += c)
#define rloop(i, a, b, c) for (i = a; i > b; i -= c)
using namespace std;
using namespace std::chrono;
ll mod = 1000000007;

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

struct node *reverse (struct node *head, int k)
{
    int x = 0;
    node *s,*e,*ns,*ps;
    s = head;
    ns = head;
    node *cur,*pre=NULL,*n;
    cur = head;
    while(ns!=NULL)
    {
        e = ns;
        ns = ns->next;
        x+=1;
        n = cur->next;
        cur->next = pre;
        pre = cur;
        cur = n;
        if(x==k||ns==NULL)
        {
            if(s==head)
            head = e;
            else
            ps->next = e;
            ps = s;
            s = ns;
            x = 0;
            pre = NULL;
        }
    }
    return head;
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

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
        
        head = reverse(head, k);
        printList(head);
    }
     
    return(0);
}



