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
    void traverseAndDelete(TreeNode* &p,int target){
        if(p==NULL)
            return;
        traverseAndDelete(p->left,target);
        traverseAndDelete(p->right,target);
        if(p->val==target&&p->left==p->right){
            p=NULL;
        }
        return;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        traverseAndDelete(root,target);
        return root;
    }
};