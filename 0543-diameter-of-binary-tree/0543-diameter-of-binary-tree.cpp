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
    int f(TreeNode* root,vector<int> &h){
        if(root==NULL) return 0;
        int lh=1+f(root->left,h);
         int rh=1+f(root->right,h);
        h[0]=max(h[0],lh+rh-2);
       return max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> h{0};
        f(root,h);
        return h[0];
    }
};