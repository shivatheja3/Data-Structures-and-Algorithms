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
    void inOrder(vector<int> &l,TreeNode *p){
        if(p){
            inOrder(l,p->left);
            l.push_back(p->val);
            inOrder(l,p->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> r1;
        inOrder(r1,root);
        int l=0,r=r1.size()-1;
        while(l<r){
            if((r1[l]+r1[r])==k){
                return true;
            }
            else if((r1[l]+r1[r])<k){
                ++l;
            }
            else{
                --r;
            }
        }
        return false;
    }
};