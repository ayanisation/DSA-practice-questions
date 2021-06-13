#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

class Solution{
  public:
    Node * mergeKLists(Node *arr[], int K)
    {
        multiset<int>s;
        for(int i=0;i<K;i++){
            Node* h = arr[i];
            while(h){
                s.insert(h->data);
                h=h->next;
            }
        }
        Node* head = new Node(*(s.begin()));
        Node* hc = head;
        for(auto it=++(s.begin());it!=s.end();++it){
            hc->next = new Node(*it);
            hc=hc->next;
        }
        return head;
    }
};

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}