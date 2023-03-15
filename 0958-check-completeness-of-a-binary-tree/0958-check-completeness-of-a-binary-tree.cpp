/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        vector<int> r;
        TreeNode *p=root;
        queue<TreeNode *> q;
        q.push(p);
        r.push_back(root->val);
        while(q.size()!=0){
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left){
                r.push_back(temp->left->val);
                q.push(temp->left);
            }
            else{
                if(r[r.size()-1]!=-1){
                    r.push_back(-1);
                }
            }
            if(temp->right){
                r.push_back(temp->right->val);
                q.push(temp->right);
            }
            else{
                // r.push_back(-1);
                if(r[r.size()-1]!=-1){
                    r.push_back(-1);
                }
            }
        }
        if(r.size()==1){
            return true;
        }
        int i=0;
        cout<<r[0]<<" ";
        for(i=1;i<(r.size()-1);++i){
            cout<<r[i]<<" ";
            if(r[i]==-1&&((r[i-1]>0)&&r[i+1]>0)){
                return false;
            }
            
        }
        cout<<r[i];
        cout<<endl;
        return true;
    }
};