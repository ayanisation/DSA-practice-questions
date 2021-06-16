
#include<bits/stdc++.h>
using namespace std;

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

class Solution{
    int findIndex(int in[],int num,int l,int r){
        for(int i=l;i<=r;i++){
            if(in[i]==num)
            return i;
        }
        return -1;
    }
    Node* build(int in[],int pre[],int &cur,int l,int r){
        if(l>r)
        return NULL;
        int m = findIndex(in,pre[cur],l,r);
        Node* n = new Node(pre[cur++]);
        n->left = build(in,pre,cur,l,m-1);
        n->right = build(in,pre,cur,m+1,r);
        return n;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int cur = 0;
        Node* r = build(in,pre,cur,0,n-1);
        return r;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}