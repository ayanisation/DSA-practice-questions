#include<bits/stdc++.h> 
 
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
}; 

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* h=head;
    while(h){
        if(h->next==head){
            h->next=NULL;
        }
      h=h->next;
    }
    h = head;
    Node* l = head;
    while(l->next&&(l->next)->next){
        h = h->next;
        l = (l->next)->next;
    }
    l = h->next;
    h->next=head;
    *head1_ref=head;
    Node* head2 = l;
    h=l;
    while(true){
        if(h->next==NULL){
            h->next=head2;
            break;
        }
        h=h->next;
    }
    *head2_ref=head2;
}

void printList(struct Node *head)
{
  struct Node *temp = head; 
  if(head != NULL)
  {
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
    printf("\n");
  }
}

 
int main()
{
  
   int t,n,i,x;
    scanf("%d",&t);
   while(t--)
   {
	   struct Node *temp,*head = NULL;
       struct Node *head1 = NULL;
       struct Node *head2 = NULL;
	   scanf("%d",&n);
	   scanf("%d",&x);
	   head=new Node(x);
	   temp=head;
	   for(i=0;i<n-1;i++){
	   scanf("%d",&x);
	   
	   temp->next=new Node(x);
	   
	   temp=temp->next;
	       
	   }
       
       temp->next=head;
  
      splitList(head, &head1, &head2);
      printList(head1);  
      printList(head2);  
   
   }
  return 0;
}

