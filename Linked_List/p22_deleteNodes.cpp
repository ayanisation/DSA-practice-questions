#include<bits/stdc++.h>

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


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

class Solution
{
    public:
    Node *compute(Node *head)
    {
        vector<int>v;
        while(head){
            v.push_back(head->data);
            head=head->next;
        }
        vector<int>vmax(v.size());
        int m = 0;
        for(int i=v.size()-1;i>=0;i--){
            m = max(v[i],m);
            vmax[i]=m;
        }
        Node* h = NULL;
        Node* hc = NULL;
        for(int i=0;i<v.size();i++){
            if(vmax[i]==v[i]){
                if(!h){
                    h = new Node(v[i]);
                    hc=h;
                }
                else{
                    hc->next = new Node(v[i]);
                    hc=hc->next;
                }
            }
        }
        return h;
    }
    
};

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}