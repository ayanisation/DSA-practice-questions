#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

bool search(Node* r,int a){
    if(!r)
    return false;
    if(a>r->data)
    search(r->right,a);
    else if(a<r->data)
    search(r->left,a);
    else
    return true;
}
int countPairs(Node* root1, Node* root2, int x)
{
    if(!root1)
    return 0;
    else if(search(root2,x-root1->data))
    return 1+countPairs(root1->left,root2,x)+countPairs(root1->right,root2,x);
    else 
    return countPairs(root1->left,root2,x)+countPairs(root1->right,root2,x);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}

