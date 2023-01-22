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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root){
            return {};
        }
        int control=1;
        vector<TreeNode *> q1,q2;
        vector<vector<int>> res;
        vector<int> cL;
        q1.insert(q1.begin(),root);
        while(q1.size()!=0||q2.size()!=0){
            if(control==1){
                if(q1[0]->left){
                    q2.insert(q2.end(),q1[0]->left);
                }
                if(q1[0]->right){
                    q2.insert(q2.end(),q1[0]->right);
                }
                cL.push_back(q1[0]->val);
                q1.erase(q1.begin());
                if(q1.size()==0){
                    control=2;
                    res.push_back(cL);
                    cL={};
                }
            }
            else{
                if(q2[0]->left){
                    q1.insert(q1.end(),q2[0]->left);
                }
                if(q2[0]->right){
                    q1.insert(q1.end(),q2[0]->right);
                }
                cL.push_back(q2[0]->val);
                q2.erase(q2.begin());
                if(q2.size()==0){
                    control=1;
                    res.push_back(cL);
                    cL={};
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};