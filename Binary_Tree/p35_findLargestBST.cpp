#include<bits/stdc++.h>
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
//main logic
vector<int> solve(Node* n){
    if(!n)
    return {1,0,INT_MAX,0};
    vector<int>l = solve(n->left);
    vector<int>r = solve(n->right);
    if(l[0]&&r[0]&&n->data>l[3]&&n->data<r[2])
    return {1,l[1]+r[1]+1,min(n->data,min(l[2],r[2])),max(n->data,max(l[3],r[3]))};
    else 
    return {0,max(l[1],r[1]),INT_MAX,0};
}
int largestBst(Node *root)
{
	vector<int>v = solve(root);
	return v[1];
}

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}

