#include<bits/stdc++.h>
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
 
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    
    return new_Node;
}
 
 
 Node *reverse(Node **r)
{
    Node *prev =NULL;
    Node *cur = *r;
    Node *nxt;
    while(cur!=NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_Node = newNode(new_data);
 
    new_Node->next = (*head_ref);
 
    (*head_ref) = new_Node;
}


void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {

        temp=Node;
        Node = Node->next;
        free(temp);
    }

}

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    long long m = 1000000007; 
    long long n1=0,n2=0;
    while(l1){
        n1=((n1%m)*10)%m+(l1->data);
        l1=l1->next;
    }
    while(l2){
        n2=((n2%m)*10)%m+(l2->data);
        l2=l2->next;
    }
    return(n1*n2)%m;
}
 
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
 
int main(void)
{


   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {

    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
         cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    push(&second, x);
	    }

	     reverse(&first);
	     reverse(&second);
		 long long res = multiplyTwoLists(first,second);
	    
	    cout<<res<<endl;
        freeList(first);
        freeList(second);

   }
   return 0;
}

