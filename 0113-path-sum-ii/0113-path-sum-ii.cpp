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
    void check(TreeNode *p,int s,int t,vector<vector<int>> &res,vector<int> &t1){
        if(p){
            s=s+p->val;
            t1.push_back(p->val);
            if(p->left==NULL&&p->right==NULL){
                if(s==t)
                    res.push_back(t1);
            }
            check(p->left,s,t,res,t1);
            check(p->right,s,t,res,t1);
            t1.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> t1;
        vector<vector<int>> res;
        check(root,0,targetSum,res,t1);
        return res;
    }
};