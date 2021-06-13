
#include <bits/stdc++.h>
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
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution{
public:
    Node* divide(int N, Node *head){
        vector<int>even,odd;
        
        while(head){
            if((head->data)%2)
            odd.push_back(head->data);
            else
            even.push_back(head->data);
            head=head->next;
        }
        
        Node* h = NULL;
        Node* hc = NULL;
        for(int i=0;i<even.size();i++){
            if(!h){
                h = new Node(even[i]);
                hc=h;
            }
            else{
                hc->next = new Node(even[i]);
                hc=hc->next;
            }
        }
        for(int i=0;i<odd.size();i++){
            if(!h){
                h = new Node(odd[i]);
                hc=h;
            }
            else{
                hc->next = new Node(odd[i]);
                hc=hc->next;
            }
        }
        return h;
    }
};

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}