#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution{
    Node* merge(Node* h1, Node* h2){
        Node* head = NULL;
        if(h1->data<=h2->data){
            head = new Node(h1->data);
            h1=h1->next;
        }
        else{
            head = new Node(h2->data);
            h2=h2->next;
        }
        Node* h=head;
        while(h1&&h2){
            if(h1->data<=h2->data){
                h->next = new Node(h1->data);
                h1=h1->next;
            }
            else{
                h->next = new Node(h2->data);
                h2=h2->next;
            }
            h=h->next;
        }
        while(h1){
            h->next = new Node(h1->data);
            h1=h1->next;
            h=h->next;
        }
        while(h2){
            h->next = new Node(h2->data);
            h2=h2->next;
            h=h->next;
        }
        return head;
    }
  public:
    Node* mergeSort(Node* head) {
        Node* h = head;
        Node* l = head;
        while(l->next&&(l->next)->next){
            h = h->next;
            l = (l->next)->next;
        }
        Node* h2 = h->next;
        h->next=NULL;
        if(h2){
            head = mergeSort(head);
            h2 = mergeSort(h2);
            head = merge(head,h2);
        }
        return head;
    }
};


void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  