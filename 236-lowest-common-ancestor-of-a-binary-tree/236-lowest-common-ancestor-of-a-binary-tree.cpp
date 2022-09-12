/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* func(TreeNode *r,TreeNode *p,TreeNode* q){
        if(r==p||r==q||r==NULL){
            return r;
        }
        TreeNode *left=func(r->left,p,q);
        TreeNode *right=func(r->right,p,q);
        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return r;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root,p,q);
    }
};