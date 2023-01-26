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
    int ind=0;
    TreeNode* f(vector<int>& in,vector<int>& po,unordered_map<int,int> &h1,int low,int high){
        if(low>high) return NULL;
        int pos=h1[po[po.size()-1-ind]];
        TreeNode *root=new TreeNode(po[po.size()-1-ind++]);
        root->right=f(in,po,h1,pos+1,high);
        root->left=f(in,po,h1,low,pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> h1;
        for(int i=0;i<inorder.size();++i){
            h1[inorder[i]]=i;
        }
        int low=0,high=postorder.size()-1;
        return f(inorder,postorder,h1,low,high);
    }
};