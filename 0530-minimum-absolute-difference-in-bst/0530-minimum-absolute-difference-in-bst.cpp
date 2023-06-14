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
    void inOrder(TreeNode *p,vector<int> &res){
        if(p){
            inOrder(p->left,res);
            res.push_back(p->val);
            inOrder(p->right,res);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        inOrder(root,res);
        int i=0;
        int min1=res[1]-res[0];
        for(i=1;i<res.size()-1;i++){
            if(res[i+1]-res[i]<min1){
                min1=res[i+1]-res[i];
            }
        }
        return min1;
    }
};