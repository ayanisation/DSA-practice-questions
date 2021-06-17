#include <bits/stdc++.h>

using namespace std;

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

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int path(Node* r,int n,vector<Node*> &p){
    if(!r)
    return 0;
    p.push_back(r);
    if(r->data==n)
    return 1;
    if(path(r->left,n,p) || path(r->right,n,p))
    return 1;
    p.pop_back();
    return 0;
}
int findDist(Node* root, int a, int b) {
    vector<Node*>p1;
    vector<Node*>p2;
    path(root,a,p1);
    path(root,b,p2);
    p1.push_back(NULL);
    p2.push_back(NULL);
    int i=0;
    int s = min(p1.size(),p2.size());
    for(;i<s;i++){
        if(p1[i]==NULL||p2[i]==NULL||p1[i]!=p2[i]){
            i-=1;
            break;
        }
    }
    int dis1 = (p1.size()-2)-i;
    int dis2 = (p2.size()-2)-i;
    return dis1+dis2;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}