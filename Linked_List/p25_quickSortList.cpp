#include <iostream>
#include <cstdio>
using namespace std;
 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = new node(new_data);
 
    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
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

struct node* partition(struct node *head,struct node *tail){
    node* pivot=head;
    node* current=head->next;
    node* prev=head;
    while(current!=tail->next){
        if(current->data<pivot->data){
            swap(current->data,prev->next->data);
            prev=prev->next;
        }
        current = current->next;
    }
    swap(prev->data,pivot->data);
    return prev;
}

void qsortrec(struct node *head,struct node *tail){
    if(!head || !tail || head==tail)
    return;
    node* pivot = partition(head,tail);
    qsortrec(head,pivot);
    qsortrec(pivot->next,tail);
    
}

void quickSort(struct node **headRef) {
    node* tail = *headRef;
    while(tail->next)
    tail = tail->next;
    qsortrec(*headRef,tail);
    
}

int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}
