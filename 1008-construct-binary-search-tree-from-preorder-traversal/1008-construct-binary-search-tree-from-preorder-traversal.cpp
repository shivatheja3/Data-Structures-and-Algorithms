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
    int idx=0;
    TreeNode *f(vector<int> &pre,vector<int> &in,unordered_map<int,int> &h1,int low,int high){
        if(low>high) return NULL;
        int pos=h1[pre[idx]];
        TreeNode *root=new TreeNode(pre[idx++]);
        root->left=f(pre,in,h1,low,pos-1);
        root->right=f(pre,in,h1,pos+1,high);
        return root;
    } 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> h1;
        for(int i=0;i<inorder.size();++i){
            h1[inorder[i]]=i;
        }
        int low=0,high=preorder.size()-1;
        return f(preorder,inorder,h1,low,high);
    }
};