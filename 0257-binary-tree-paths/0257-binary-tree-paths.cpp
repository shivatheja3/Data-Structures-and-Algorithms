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
    void traverse(TreeNode *temp,vector<vector<TreeNode*>> &res,queue<vector<TreeNode*>> &q){
        while(q.size()!=0){
            vector<TreeNode*> temp=q.front();
            q.pop();
            TreeNode *t=temp[temp.size()-1];
            if(t->left){
                vector<TreeNode*> t1=temp;
                t1.push_back(t->left);
                q.push(t1);
            }
            if(t->right){
                vector<TreeNode*> t1=temp;
                t1.push_back(t->right);  
                q.push(t1);
            }
            if(t->left==NULL&&t->right==NULL){
                res.push_back(temp);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<TreeNode*>> res;
        queue<vector<TreeNode*>> q;
        q.push({root});
        traverse(root,res,q);
        vector<string> r;
        for(int i=0;i<res.size();++i){
            string s="";
            for(int j=0;j<(res[i].size()-1);++j){
                s+=to_string(res[i][j]->val);
                s+="->";
            }
            if(res[i].size()>0){
                s+=to_string(res[i][res[i].size()-1]->val);
            }
            if(s.size()>0){
                r.push_back(s);
            }
        }
       
        return r;
    }
};