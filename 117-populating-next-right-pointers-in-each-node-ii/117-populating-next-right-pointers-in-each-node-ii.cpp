/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node *>> res;
        vector<Node *> q;
        if(!root){
            return NULL;
        }
        q.insert(q.begin(),root);
        while(q.size()!=0){
            int s=q.size();
            vector<Node *> cL;
            for(int i=0;i<s;i++){
                Node* a=q[0];
                if(q[0]->left){
                    q.insert(q.end(),q[0]->left);
                }
                if(q[0]->right){
                    q.insert(q.end(),q[0]->right);
                }
                q.erase(q.begin());
                cL.push_back(a);
            }
            res.push_back(cL);
        }
        for(int i=0;i<res.size();++i){
            for(int j=0;j<res[i].size();++j){
                if(j!=(res[i].size()-1)){
                    res[i][j]->next=res[i][j+1];
                }
                else{
                    res[i][j]->next=NULL;
                }
            }
        }
        return root;
    }
};