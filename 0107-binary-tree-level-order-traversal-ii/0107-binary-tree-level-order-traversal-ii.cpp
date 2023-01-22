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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode *> q;
        if(!root){
            return res;
        }
        TreeNode *dummy=new TreeNode(-1001);
        q.insert(q.begin(),root);
        vector<int> cL;
        q.insert(q.end(),dummy);
        while(q.size()!=1){
            // int a=q[0]->val;
            cL.push_back(q[0]->val);
            if(q[0]->left){
                q.insert(q.end(),q[0]->left);
            }
            if(q[0]->right){
               q.insert(q.end(),q[0]->right);
            }
            q.erase(q.begin());
            if(q[0]==dummy){
                q.erase(q.begin());
                res.push_back(cL);
                cL={};
                q.insert(q.end(),dummy);
            }
            // res.push_back(cL);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};