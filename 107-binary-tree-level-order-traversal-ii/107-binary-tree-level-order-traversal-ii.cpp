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
        q.insert(q.begin(),root);
        while(q.size()!=0){
            int s=q.size();
            vector<int> cL;
            for(int i=0;i<s;i++){
                int a=q[0]->val;
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
        reverse(res.begin(),res.end());
        return res;
    }
};