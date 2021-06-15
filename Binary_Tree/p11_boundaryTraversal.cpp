#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    vector<int>v;
    stack<int>s;
    set<Node*>st;
    
    void leafs(Node* r){
        if(!r)
        return;
        if(!r->left && !r->right){
            if(st.find(r)==st.end()){
                v.push_back(r->data);
                st.insert(r);
            }
            return;
        }
        leafs(r->left);
        leafs(r->right);
    }
    
    vector <int> printBoundary(Node *root)
    {
        Node* n = root->left;
        v.push_back(root->data);
        st.insert(root);
        while(n){
            v.push_back(n->data);
            st.insert(n);
            if(n->left)
            n=n->left;
            else n=n->right;
        }
        leafs(root);
        n = root->right;
        while(n){
            if(st.find(n)==st.end()){
                s.push(n->data);
                st.insert(n);
            }
            if(n->right)
            n=n->right;
            else
            n=n->left;
        }
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
} 