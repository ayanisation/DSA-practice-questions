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

struct Node *start = NULL;

Node* segregate(Node *head) {
    
    multiset<int>s;
    while(head!=NULL)
    {
        s.insert(head->data);
        head = head->next;
    }
    Node *h = new Node(*s.begin());
    s.erase(s.begin());
    Node *t = h;
    for(auto it : s)
    {
        t->next = new Node(it);
        t = t->next;
    }
    return h;
}

void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void insert(int n1) {
    int n, value, i;
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        struct Node *newHead = segregate(start);
        printList(newHead);
    }

    return 0;
}


