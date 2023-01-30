//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    void f(Node *p,int v,int d,unordered_map<int, pair<int,int> > &h1,int &min1,int &max1){
        if(p==NULL) return;
        // cout<<v<<" "<<h1[v].first<<" "<<h1[v].second<<" "<<d<<endl;
        if(h1.find(v)!=h1.end()){
            // cout<<v<<" "<<h1[v].first<<" "<<h1[v].second<<" "<<d<<"in1"<<endl;
            if(h1[v].first>d){
                // cout<<v<<" "<<h1[v].first<<" "<<h1[v].second<<" "<<d<<"in2"<<endl;
                h1[v]={d,p->data};
            }
        }
        else{
            h1[v]={d,p->data};
        }
        // cout<<v<<" "<<h1[v].first<<" "<<h1[v].second<<" "<<d<<endl;
        min1=min(v,min1);
        max1=max(v,max1);
        f(p->left,v-1,d+1,h1,min1,max1);
        f(p->right,v+1,d+1,h1,min1,max1);
    }
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        int v=0,d=0,min1=100001,max1=-100001;
        unordered_map<int, pair<int,int>> h1;
        f(root,v,d,h1,min1,max1);
        vector<int> res;
        for(int i=min1;i<=max1;++i){
            // cout<<h1[i].second<<" ";
            res.push_back(h1[i].second);
        }
        return res;
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends