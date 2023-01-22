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
    void check(TreeNode *p,int s,int t,bool &res){
        if(p){
            s=s+p->val;
            if(p->left==NULL&&p->right==NULL){
                if(s==t)
                    res=true;
            }
            check(p->left,s,t,res);
            check(p->right,s,t,res);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res=false;
        check(root,0,targetSum,res);
        return res;
    }
};